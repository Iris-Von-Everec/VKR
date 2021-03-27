#ifndef MANAGER_H
#define MANAGER_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QFileSystemModel>
#include <QDirModel>
#include <QTreeView>
#include <QFileSystemModel>
#include <QtGui>
#include <QtCore>
#include <QDir>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class Manager; }
QT_END_NAMESPACE

class Manager : public QMainWindow
{
    Q_OBJECT

  public:
    Manager(QWidget *parent = nullptr);
    ~Manager();
    void Initialization();
    void read_json(); // чтение json, переместить в нужный классь из Manager
    void write_json(); // запись json, переместить в нужный класс из Manager
    void Debug__();
    void closeEvent(QCloseEvent *event);

  private slots:
    void clicked_exit();
    void on_tree_view_activated(const QModelIndex &index); // double click
    void on_tree_view_clicked(const QModelIndex &index); // отображеине файлов из дерева в список

private:
    Ui::Manager *ui;
    QFileSystemModel *dirs_model, *files_model;
    QString start_path, current_path;
    QAction *exit;
};
#endif // MANAGER_H
