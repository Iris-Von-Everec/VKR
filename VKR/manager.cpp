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
}

Manager::~Manager()
{
  delete exit;
  delete ui;
}

void Manager::Initialization()
{
 // зачем?
}

void Manager::clicked_exit()
{
  this->close();
}

void Manager::Debug__()
{
 // отладка
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
   qDebug() << current_path;
 //  qDebug() << index.data().toString();
   files_model->setRootPath(current_path);
   ui->listView->setRootIndex(files_model->setRootPath(current_path));
}

void Manager::write_json()
{
  QJsonObject recordObject;
  recordObject.insert("Test1", QJsonValue::fromVariant("1"));
  recordObject.insert("Test2", QJsonValue::fromVariant(123.4));
  recordObject.insert("Test3", QJsonValue::fromVariant(43));
  recordObject.insert("Test4", QJsonValue::fromVariant(true));
  recordObject.insert("Test5",   QJsonValue::fromVariant(QByteArray("1,2,3,4,5")));
  QJsonArray numbersArray;
  numbersArray.push_back("1");
  numbersArray.push_back("2");
  numbersArray.push_back("3");
  recordObject.insert("Test6",numbersArray);
  QJsonDocument doc(recordObject);
  QString jsonString = doc.toJson(QJsonDocument::Indented);
  //Записываем данные в файл
  QFile file;
  file.setFileName("test1.json");
  file.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream stream( &file );
  stream << jsonString;
  file.close();
}
