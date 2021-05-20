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
#include <QJsonValue>
#include <QJsonParseError>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QScreen>
#include <QWidget>
#include <QPushButton>
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
    void check_sum_of_files();

  private slots:
    void clicked_exit();
    void button1_clicked();
    void button2_clicked();
    void button3_clicked();
    void button4_clicked();
    void button5_clicked();

  protected:
    virtual void resizeEvent(QResizeEvent *);

  private:
    Ui::Manager *ui;
    QFileSystemModel *dirs_model, *files_model;
    QString start_path, current_path, json_path, json_string;
    QAction *exit;
    QFile json_file;
    QString hash_sum; //временно для проверки сравнения хэша

    QSize scr_size;
    QRect main_size;
    QWidget *info_widget, *content_widget;
    QHBoxLayout *main_layout, *content;
    QVBoxLayout *info_panel;
    QPushButton *button1, *button2, *button3, *button4, *button5;

    void Set_info_panel();

};
#endif // MANAGER_H
