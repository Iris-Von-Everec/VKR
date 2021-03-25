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
    ui->tree_view->setRootIndex(files_model->setRootPath(start_path));

   // file_system.CreateDir(); // Dir
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
 //
}

void Manager::clicked_exit()
{
  this->close();
}

void Manager::Debug__()
{

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
   qDebug() << index.data().toString();
   files_model->setRootPath(current_path);
   ui->listView->setRootIndex(files_model->setRootPath(current_path));
}
