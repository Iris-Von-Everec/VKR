#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Manager)
{
    ui->setupUi(this);
    scr = QApplication::desktop()->screenGeometry();
   // this->resize(scr.width(), scr.height());
    this->showFullScreen();
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
