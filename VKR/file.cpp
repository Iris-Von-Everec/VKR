#include "file.h"

File::File()
{

}

File::~File()
{

}

QByteArray File::get_checksum()
{
  return this->checksum;
}

void File::update_checksum(QByteArray new_checksum)
{
  this->checksum = new_checksum;
}

QByteArray File::calc_checksum()
{
  // Возвращает пустой QByteArray() в случае ошибки
  QFile f(this->filename);
  if(f.open(QFile::ReadOnly))
    {
      QCryptographicHash hash(QCryptographicHash::Sha256);
      if (hash.addData(&f))
        {
          return hash.result();
        }
    }
  return QByteArray();
}

QString File::get_filename()
{
  return this->filename;
}

void File::update_filename(QString new_name)
{
  this->filename = new_name;
}

QString File::get_path()
{
  return this->path_file;
}

void File::update_path(QString new_path)
{
  this->path_file = new_path;
}

bool File::is_same()
{
  if(this->is_exist() == true)
    {

    }
  else
    return false;
}

bool File::is_exist()
{
  QFile f(this->path_file);
  if(f.exists() == true)
    return true;
  else
    return false;
}

void File::add_tag(Tag *tag)
{
  this->tags.push_back(tag);
}
