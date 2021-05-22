#ifndef TAGS_H
#define TAGS_H

#include <QString>
#include <QVector>
#include <set>

typedef struct Node
{
  QString tag_name; // имя тега
  Node* parent; // родитель
  bool has_children; // есть ли дочерние элементы
  QVector <Node> children; // вектор дочерних элементов
} Node;

class Tags
{
  public:
    Tags();
    ~Tags();
    Node* find_in_child(QString tag_name, Node* where);
    Node* find_by_name(QString tag_name);
    int add_tag(QString tag_name, QString parent, bool prime);
  private:
    QVector <Node> tag_list;
    std::set<QString> tags_names;
};

#endif // TAGS_H
