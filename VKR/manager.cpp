#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Manager)
{
    ui->setupUi(this);
    scr = QApplication::desktop()->screenGeometry();
    this->setGeometry(0, 0, 1920, 1080);
  //  this->resize(scr.width(), scr.height());
 //   this->mapToGlobal(QPoint(0,0));
 //   this->showFullScreen();

    QString sPath ="c:/";
    filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot);
    filemodel->setNameFilterDisables(false);
    filemodel->setRootPath(sPath);
    ui->file_system->setModel(filemodel);
    ui->file_system->setRootIndex(filemodel->setRootPath(sPath));
}

Manager::~Manager()
{
    delete ui;
}

void Manager::Initialization()
{

}

void Manager::Debug__()
{
  qDebug() << scr.height() << scr.width();
}
