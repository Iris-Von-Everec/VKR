#include "filesystem.h"

FileSystem::FileSystem()
{
  QString sPath ="";
  filemodel = new QFileSystemModel();
  filemodel->setFilter(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot);
  filemodel->setRootPath(sPath);
  filemodel->setNameFilterDisables(false);
}

FileSystem::~FileSystem()
{
  delete filemodel;
}

QFileSystemModel* FileSystem::Get_File_system()
{
  return filemodel;
}

QString FileSystem::path_of_index(const QModelIndex &index)
{
  return filemodel->filePath(index);
}

QString FileSystem::name_of_index(const QModelIndex &index)
{
  return filemodel->fileName(index);
}

void FileSystem::set_name_filter(QStringList filter_name)
{
  filemodel->setNameFilters(filter_name);
}

void FileSystem::file_filter()
{
  filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files) ;
}
