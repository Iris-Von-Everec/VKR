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
#include "file_system.h"

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
    void Debug__();
    void closeEvent(QCloseEvent *event);

  private slots:
    void clicked_exit();
    void on_tree_view_activated(const QModelIndex &index);
    void on_tree_view_clicked(const QModelIndex &index);

private:
    Ui::Manager *ui;
    QFileSystemModel *dirs_model, *files_model;
    File_System f_system;
    QString start_path, current_path;
    QAction *exit;
};
#endif // MANAGER_H
