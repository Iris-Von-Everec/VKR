#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QVector>
#include "tag.h"

class File
{
  public:
    File();
    ~File();
  private:
    QString filename, path_file;
    QVector <Tag> tags;
    QByteArray checksum;
    unsigned int rating;
};

#endif // FILE_H
