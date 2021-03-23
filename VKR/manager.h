#ifndef MANAGER_H
#define MANAGER_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QFileSystemModel>
#include "QDirModel"
#include "QTreeView"
#include "QFileSystemModel"
#include "QtGui"
#include "QtCore"
#include "QDir"
#include <QDebug>

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

private:
    Ui::Manager *ui;
    QRect scr;
    QFileSystemModel *filemodel;
};
#endif // MANAGER_H
