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
#include <QListView>
#include <QLineEdit>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QMenu>

#include "filesystem.h"
#include "file_search.h"
#include "data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Manager; }
QT_END_NAMESPACE

class Manager : public QMainWindow
{
  Q_OBJECT

  public:
    Manager(QWidget *parent = nullptr);
    ~Manager();
    void read_json(); // чтение json, переместить в нужный класс из Manager
    void write_json(); // запись json, переместить в нужный класс из Manager
    void Debug__();
    void closeEvent(QCloseEvent *event);

  private slots:
    void clicked_exit();
    void button1_clicked();
    void button2_clicked();
    void button3_clicked();
    void button4_clicked();
    void button5_clicked();
    void get_full_path(const QModelIndex &index);
    void on_about_programm_triggered();
    void on_about_aut_triggered();
    void on_white_content_triggered();
    void on_black_content_triggered();
    void on_red_content_triggered();
    void on_blue_content_triggered();
    void on_white_panel_triggered();
    void on_black_panel_triggered();
    void on_red_panel_triggered();
    void on_blue_panel_triggered();
    void create_context_menu_tag(const QPoint &pos);


protected:
    virtual void resizeEvent(QResizeEvent *);
    virtual void keyPressEvent(QKeyEvent *event);

  private:
    Ui::Manager *ui;

    FileSystem filesystem;
    Window *explorer;

    QAction *exit;
    QSize scr_size;
    QRect content_size;
    QWidget *info_widget, *empty_widget, *filesystem_search_widget;
    QStackedWidget *content_widget;
    QHBoxLayout *main_layout;
    QVBoxLayout *info_layout, *file_search_layout;
    QPushButton *button1, *button2, *button3, *button4, *button5;
    QStandardItemModel *tags_model;
    QStandardItem *tag_item1, *tag_item2, *tag_item3, *root_item;
    QTreeView *tree_view, *tags_tree;

    void Set_info_panel();
    void add_ex_tag();
    void add_new_tag();
};
#endif // MANAGER_H
