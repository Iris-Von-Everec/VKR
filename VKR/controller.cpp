#include "controller.h"

Controller::Controller()
{
  QString sPath ="";
  filemodel = new QFileSystemModel();
  filemodel->setFilter(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot);
  filemodel->setNameFilterDisables(false);
  filemodel->setRootPath(sPath);
}


Controller::~Controller()
{
  delete filemodel;
}

QFileSystemModel* Controller::Get_File_system()
{
  return filemodel;
}

QString Controller::path_of_index(const QModelIndex &index)
{
  return filemodel->filePath(index);

}
