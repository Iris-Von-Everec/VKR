#ifndef DATA_H
#define DATA_H

#include <QVector>

#include "tag.h"
#include "file.h"
#include "filesystem.h"

class Data
{
  public:
    Data();
    ~Data();
  private:
    QVector <Tag> tags;
    QVector <File> files;
};

#endif // DATA_H
