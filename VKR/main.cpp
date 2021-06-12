#include "manager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Manager w;
  w.show();
  w.Debug__();
  return a.exec();
}
