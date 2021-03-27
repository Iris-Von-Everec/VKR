#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Manager)
{
    ui->setupUi(this);
    start_path = "";
    dirs_model = new QFileSystemModel(this);
    dirs_model->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    dirs_model->setNameFilterDisables(false);
    dirs_model->setRootPath(start_path);
    ui->tree_view->setModel(dirs_model);
    ui->tree_view->setRootIndex(dirs_model->setRootPath(start_path));

    files_model = new QFileSystemModel(this);
    files_model->setFilter(QDir::Files);
    files_model->setNameFilterDisables(false);
    files_model->setRootPath(start_path);
    ui->listView->setModel(files_model);
    ui->listView->setRootIndex(files_model->setRootPath(start_path));

    this->setGeometry(0, 0, 1920, 1080);
    this->showMaximized();
    exit = new QAction("Выход", this);
    ui->menubar->addAction(exit);
    connect(exit, SIGNAL(triggered()), this, SLOT(clicked_exit()));

    json_path = PRO_FILE_PWD;
    json_path.append("/test1.json");
    qDebug() << json_path;
   // write_json();
    read_json();
    check_sum_of_files();
}

Manager::~Manager()
{
  delete exit;
  delete ui;
}

void Manager::Initialization()
{
 // зачем? Инициализация подклассов
}

void Manager::clicked_exit()
{
  this->close();
}

void Manager::Debug__()
{
 // отладка
 // qDebug() << PRO_FILE_PWD;
}

void Manager::closeEvent(QCloseEvent *event)
{
  // do some data saves or something else
  qApp->quit();
}

void Manager::on_tree_view_activated(const QModelIndex &index)
{
   // qDebug() << "Да";
}

void Manager::on_tree_view_clicked(const QModelIndex &index)
{
   current_path = dirs_model->filePath(index);
 //  qDebug() << current_path;
 //  qDebug() << index.data().toString();
   files_model->setRootPath(current_path);
   ui->listView->setRootIndex(files_model->setRootPath(current_path));
}

void Manager::read_json()
{
  QString value;
  json_file.setFileName(json_path);
  json_file.open(QIODevice::ReadOnly | QIODevice::Text);
  value = json_file.readAll();
  json_file.close();
  QJsonDocument document = QJsonDocument::fromJson(value.toUtf8());
  QJsonObject json_obj = document.object();
  QJsonValue json_value = json_obj.value("Tag_1");
  if (json_value.isObject())
  {
      QJsonObject file_obj = json_value.toObject();
      QJsonValue file_value = file_obj.value("File Name 1");
      if (file_value.isObject())
        {
          QJsonObject final_obj = file_value.toObject();
          hash_sum = final_obj["Hash sum"].toString();
          QString file_path = final_obj["Path"].toString();
          QString file_type = final_obj["type"].toString();
      //    qDebug() << hash_sum << file_path << file_type << "\n";
        }
      else
        qDebug() << "Не считалось 2\n";
  }
  else
    qDebug() << "Не считалось 1\n";
}

// Возвращает пустой QByteArray() в случае ошибки
QByteArray fileChecksum(const QString &fileName, QCryptographicHash::Algorithm hashAlgorithm)
  {
    QFile f(fileName);
    if (f.open(QFile::ReadOnly)) {
        QCryptographicHash hash(hashAlgorithm);
        if (hash.addData(&f)) {
            return hash.result();
        }
    }
    return QByteArray();
  }

void Manager::check_sum_of_files()
{
  QByteArray file_hash_array;
  file_hash_array = fileChecksum(json_path, QCryptographicHash::Md5);
  QString hash_string = QString(file_hash_array);
  qDebug() << hash_string;
}

void Manager::write_json()
{
  QJsonObject json_obj, json_tagObj, json_subObj; // пока что без иерархии
  json_subObj.insert("Hash sum", "qwerty12345");
  json_subObj.insert("Path", PRO_FILE_PWD);
  json_subObj.insert("type", ".json");
  json_tagObj.insert("File Name 1", json_subObj);
  json_obj.insert("Tag_1", json_tagObj);
  json_subObj.insert("Hash sum", "zxcmd5sum");
  json_subObj.insert("Path", PRO_FILE_PWD);
  json_subObj.insert("type", ".txt");
  json_tagObj.insert("File Name 2", json_subObj);
  json_obj.insert("Tag_1", json_tagObj);
  /*QJsonArray numbersArray;x
  numbersArray.push_back("1");
  numbersArray.push_back("2");
  numbersArray.push_back("3"); */
  QJsonDocument document(json_obj);
  json_string = document.toJson(QJsonDocument::Indented);
  //Записываем данные в файл
  json_file.setFileName(json_path);
  json_file.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream stream(&json_file);
  stream << json_string;
  json_file.close();
}
