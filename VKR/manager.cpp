#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Manager)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, 1920, 1080);
    this->showMaximized();

    QString sPath ="c:/";
    filemodel = new QFileSystemModel(this);
    filemodel->setFilter(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot);
    filemodel->setNameFilterDisables(false);
    filemodel->setRootPath(sPath);
    ui->file_system->setModel(filemodel);
    ui->file_system->setRootIndex(filemodel->setRootPath(sPath));
    file_system.CreateDir();
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
 // qDebug() << scr.height() << scr.width();
}
