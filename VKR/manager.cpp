#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Manager)
{
    ui->setupUi(this);


    /* кусок кода с тестом парсинга json
    json_path = PRO_FILE_PWD;
    json_path.append("/test1.json");
    qDebug() << json_path;
    write_json();
    read_json();
    check_sum_of_files(); */

    // кнопка выхода в статус баре
    exit = new QAction("Выход", this);
    ui->menubar->addAction(exit);
    connect(exit, SIGNAL(triggered()), this, SLOT(clicked_exit()));

    // получение значения разрешения основного монитора
    scr_size = QApplication::screens().at(0)->availableSize();
    this->setMinimumSize(scr_size.rwidth() / 2, scr_size.rheight() / 2); // минимальный размер по ширине и высоте - половина
    this->setStyleSheet("color: black;");

    QString str = PRO_FILE_PWD;

    // info
    info_widget = new QWidget;
    info_widget->setMinimumWidth(scr_size.rheight() / 14);
    info_widget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    info_layout = new QVBoxLayout;
    Set_info_panel();
    info_widget->setLayout(info_layout);
   // this->setStyleSheet("background-color:black;");
   // info_widget->setStyleSheet("background-color: black;");

    // content
    content_widget = new QStackedWidget;
    content_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QPalette Pal(palette());
    str = PRO_FILE_PWD;
    str.append("/background.png");
    QImage back(str);
    Pal.setBrush(QPalette::Background, back);
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(Pal);

    // стек виджетов
    empty_widget = new QWidget;
    content_widget->addWidget(empty_widget);

    tree_view = new QTreeView;
    tree_view->setModel(controller.Get_File_system());
    tree_view->setRootIndex(controller.Get_File_system()->index("/"));

    connect(tree_view, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(get_full_path(const QModelIndex &)));
    content_widget->addWidget(tree_view);

    main_layout = new QHBoxLayout;
    main_layout->addWidget(info_widget);
    main_layout->addWidget(content_widget);
    main_layout->setContentsMargins(0, 0, 0, 0);
    main_layout->setSpacing(0);

    ui->centralwidget->setLayout(main_layout); // добавление основного layout на центральный виджет
    ui->statusbar->showMessage("Выберите действие");
   // this->showMaximized();
}

Manager::~Manager()
{
  delete exit;
  delete button1;
  delete button2;
  delete button3;
  delete button4;
  delete button5;
  delete info_layout;
  delete info_widget;
  delete empty_widget;
  delete tree_view;
  delete content_widget;
  delete main_layout;
  delete ui;
}

void Manager::Set_info_panel()
{
  int size = info_widget->minimumWidth();
  const QSize btnSize = QSize(size, size);
  QString str;

  // 1
  str = PRO_FILE_PWD;
  str.append("/home.png");
  button1 = new QPushButton;
  button1->setFixedSize(btnSize);
  button1->setIcon(QIcon(str));
  button1->setIconSize(btnSize);
  button1->setStyleSheet("border: 0px");
  info_layout->addWidget(button1);

  // 2
  str = PRO_FILE_PWD;
  str.append("/hard.jpg");
  button2 = new QPushButton;
  button2->setFixedSize(btnSize);
  button2->setIcon(QIcon(str));
  button2->setIconSize(btnSize);
  button2->setStyleSheet("border: 0px");
  info_layout->addWidget(button2);

  // 3
  str = PRO_FILE_PWD;
  str.append("/add.png");
  button3 = new QPushButton;
  button3->setFixedSize(btnSize);
  button3->setIcon(QIcon(str));
  button3->setIconSize(btnSize);
  button3->setStyleSheet("border: 0px");
  info_layout->addWidget(button3);

  // 4
  str = PRO_FILE_PWD;
  str.append("/add.png");
  button4 = new QPushButton;
  button4->setFixedSize(btnSize);
  button4->setIcon(QIcon(str));
  button4->setIconSize(btnSize);
  button4->setStyleSheet("border: 0px");
  info_layout->addWidget(button4);

  // 5
  str = PRO_FILE_PWD;
  str.append("/add.png");
  button5 = new QPushButton;
  button5->setFixedSize(btnSize);
  button5->setIcon(QIcon(str));
  button5->setIconSize(btnSize);
  button5->setStyleSheet("border: 0px");
  info_layout->addWidget(button5);

  connect(button1, SIGNAL(clicked()), this, SLOT(button1_clicked()));
  connect(button2, SIGNAL(clicked()), this, SLOT(button2_clicked()));
  connect(button3, SIGNAL(clicked()), this, SLOT(button3_clicked()));
  connect(button4, SIGNAL(clicked()), this, SLOT(button4_clicked()));
  connect(button5, SIGNAL(clicked()), this, SLOT(button5_clicked()));
}

void Manager::Initialization()
{
 // зачем? Инициализация подклассов
}

void Manager::clicked_exit()
{
  this->close();
}

void Manager::button1_clicked()
{
  qDebug() << "Кнопка 1";
  content_widget->setCurrentIndex(0);
  ui->statusbar->showMessage("Выберите действие");
}

void Manager::button2_clicked()
{
  qDebug() << "Кнопка 2";
  content_widget->setCurrentIndex(1);
  ui->statusbar->showMessage("Левой кнопкой мыши дважды нажмите на файл, к которому вы хотите добавить тег");
}

void Manager::button3_clicked()
{
  qDebug() << "Кнопка 3";
}

void Manager::button4_clicked()
{
  qDebug() << "Кнопка 4";
}

void Manager::button5_clicked()
{
  qDebug() << "Кнопка 5";
}

void Manager::get_full_path(const QModelIndex &index)
{
  qDebug() << controller.path_of_index(index);
}

void Manager::Debug__()
{
 // qDebug() << PRO_FILE_PWD;
}

void Manager::resizeEvent(QResizeEvent* event)
{
  Q_UNUSED(event);
  // получение размеров стека виджетов контента
  content_size = content_widget->geometry();
  tree_view->setColumnWidth(0, content_size.width() * 2 / 3);
  tree_view->setColumnWidth(1, content_size.width() / 10);
  tree_view->setColumnWidth(2, content_size.width() / 10);
  tree_view->setColumnWidth(3, content_size.width() / 10);
  qDebug() << content_size.x() << content_size.y() << content_size.width() << content_size.height();
}

void Manager::closeEvent(QCloseEvent *event)
{
  Q_UNUSED(event);
  // do some data saves or something else
  qApp->quit();
}

/*void Manager::read_json()
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
  //QJsonArray numbersArray;x
 // numbersArray.push_back("1");
  //numbersArray.push_back("2");
 // numbersArray.push_back("3");
  QJsonDocument document(json_obj);
  json_string = document.toJson(QJsonDocument::Indented);
  //Записываем данные в файл
  json_file.setFileName(json_path);
  json_file.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream stream(&json_file);
  stream << json_string;
  json_file.close();
} */
