#include "file_system.h"

File_System::File_System()
{

}

File_System::~File_System()
{

}

void File_System::CreateDir()
{
  QString str;
  str = PRO_FILE_PWD;
  str.append("/tags");
  qDebug() << str;
  if(dir.mkpath(str))
    qDebug("folder created");
  if(dir.exists(str))
    qDebug("folder exists");
}
