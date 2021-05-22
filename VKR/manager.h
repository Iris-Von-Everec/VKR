#ifndef MANAGER_H
#define MANAGER_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QtGui>
#include <QtCore>
#include <QDir>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QScreen>
#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QTreeView>

#include "controller.h"

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
    void check_sum_of_files();

  private slots:
    void clicked_exit();
    void button1_clicked();
    void button2_clicked();
    void button3_clicked();
    void button4_clicked();
    void button5_clicked();
    void get_full_path(const QModelIndex &index);

protected:
    virtual void resizeEvent(QResizeEvent *);

  private:
    Ui::Manager *ui;

    Controller controller;

    QAction *exit;
    QSize scr_size;
    QRect content_size;
    QWidget *info_widget, *empty_widget;
    QStackedWidget *content_widget;
    QHBoxLayout *main_layout;
    QVBoxLayout *info_layout;
    QPushButton *button1, *button2, *button3, *button4, *button5;
    QTreeView *tree_view, *tags_tree;

    void Set_info_panel();

};
#endif // MANAGER_H
