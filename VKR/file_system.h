#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <QDir>
#include <QDebug>

class File_System
{
  public:
    File_System();
    ~File_System();
    void CreateDir();
  private:
    QDir dir;
};

#endif // FILE_SYSTEM_H
