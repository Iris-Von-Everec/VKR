#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Manager)
{
    ui->setupUi(this);

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
   // ui->centralwidget->setPalette(Pal);

    // стек виджетов
    empty_widget = new QWidget; // домашний экран
    content_widget->addWidget(empty_widget);

    tree_view = new QTreeView; // дерево добавления тега
    tree_view->setModel(filesystem.Get_File_system());
    tree_view->setRootIndex(filesystem.Get_File_system()->index("/"));
    connect(tree_view, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(get_full_path(const QModelIndex &)));
    content_widget->addWidget(tree_view);

    explorer = new Window;
    content_widget->addWidget(explorer);

  /* filesystem_search_widget = new QWidget; // дерево поиска файлов
    file_list = new QListView;
  //  file_list->setModel(filesystem.Get_File_system());
  //  file_list->setRootIndex(filesystem.Get_File_system()->index("/"));
    text_search_file = new QLineEdit();
    text_search_file->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    text_search_file->setMaximumHeight(scr_size.height()/26);
    QFont src_font("Times New Roman", 18);
    text_search_file->setFont(src_font);
    text_search_file->installEventFilter(this);
    file_search_layout = new QVBoxLayout;
    file_search_layout->addWidget(file_list);
    file_search_layout->addWidget(text_search_file);
    file_search_layout->setContentsMargins(0, 0, 0, 0);
    file_search_layout->setSpacing(0);
    filesystem_search_widget->setLayout(file_search_layout);
    content_widget->addWidget(filesystem_search_widget); */

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
  str.append("/images/home_.png");
  button1 = new QPushButton;
  button1->setFixedSize(btnSize);
  button1->setIcon(QIcon(str));
  button1->setIconSize(btnSize);
  button1->setStyleSheet("border: 0px");
  info_layout->addWidget(button1);

  // 2
  str = PRO_FILE_PWD;
  str.append("/images/plus_.png");
  button2 = new QPushButton;
  button2->setFixedSize(btnSize);
  button2->setIcon(QIcon(str));
  button2->setIconSize(btnSize);
  button2->setStyleSheet("border: 0px");
  info_layout->addWidget(button2);

  // 3
  str = PRO_FILE_PWD;
  str.append("/images/drive_.png");
  button3 = new QPushButton;
  button3->setFixedSize(btnSize);
  button3->setIcon(QIcon(str));
  button3->setIconSize(btnSize);
  button3->setStyleSheet("border: 0px");
  info_layout->addWidget(button3);

  // 4
  str = PRO_FILE_PWD;
  str.append("/images/tag_.png");
  button4 = new QPushButton;
  button4->setFixedSize(btnSize);
  button4->setIcon(QIcon(str));
  button4->setIconSize(btnSize);
  button4->setStyleSheet("border: 0px");
  info_layout->addWidget(button4);

  // 5
  str = PRO_FILE_PWD;
  str.append("/images/search_.png");
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
  content_widget->setCurrentIndex(2);
  ui->statusbar->showMessage("Введите имя файла или директории для поиска. Нажмите Enter для поиска");
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
  qDebug() << "name:" << filesystem.name_of_index(index);
  qDebug() << "path:" << filesystem.path_of_index(index);
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
  int col1, col2;
  col1 = content_size.width() * 2 / 3;
  col2 = content_size.width() / 10;
  tree_view->setColumnWidth(0, col1);
  tree_view->setColumnWidth(1, col2);
  tree_view->setColumnWidth(2, col2);
  tree_view->setColumnWidth(3, col2);

  qDebug() << content_size.x() << content_size.y() << content_size.width() << content_size.height();
}

void Manager::keyPressEvent(QKeyEvent *event)
{
  int key = event->key(); // код клавиши
  int widget_index = content_widget->currentIndex();
  switch(widget_index)
  {
    case 0:
      break;
    case 1:

      break;

    case 2:
      if(key == Qt::Key_Enter || key == Qt::Key_Return)
      {
        qDebug() << "Enter";
      }
      break;

    case 3:
      break;

    case 4:
      break;

    case 5:
      break;

    default:
      break;
  }
}

void Manager::closeEvent(QCloseEvent *event)
{
  Q_UNUSED(event);
  // сохранение данных перед выходом
  qApp->quit();
}
