#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QFileSystemModel>
#include <QString>

class FileSystem
{
  public:
    FileSystem();
    ~FileSystem();
    QFileSystemModel* Get_File_system();
    QString path_of_index(const QModelIndex &index);
    QString name_of_index(const QModelIndex &index);
    void set_name_filter(QStringList filter_name);
    void file_filter();
  private:
    QFileSystemModel *filemodel;
    QString start_path, current_path, json_path, json_string;
};

#endif // FILESYSTEM_H
