#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QFileSystemModel>
#include <QCryptographicHash>

class Controller
{
  private:
    QFileSystemModel *filemodel;
    QString start_path, current_path, json_path, json_string;
    QFile json_file;
    QString hash_sum; //временно для проверки сравнения хэша

  public:
    Controller();
    ~Controller();
    QFileSystemModel* Get_File_system();
    QString path_of_index(const QModelIndex &index);
    //QCryptographicHash::Sha256
};

#endif // CONTROLLER_H
