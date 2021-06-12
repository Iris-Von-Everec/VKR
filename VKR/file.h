#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QCryptographicHash>

#include "tag.h"

class File
{
  public:
    File();
    ~File();
    QByteArray get_checksum();
    void update_checksum(QByteArray new_checksum);
    QByteArray calc_checksum();
    QString get_filename();
    void update_filename(QString new_name);
    QString get_path();
    void update_path(QString new_path);
    bool is_same();
    bool is_exist();
    void add_tag(Tag* tag);
  private:
    QString filename, path_file;
    QVector <Tag*> tags;
    QByteArray checksum;
    unsigned int rating;
};

#endif // FILE_H
