#ifndef TAG_H
#define TAG_H

#include <QString>
#include <QVector>

typedef struct Node
{
  QString tag_name; // имя тега
  Node* parent; // родитель
  bool has_children; // есть ли дочерние элементы
  QVector <Node> children; // вектор дочерних элементов
} Node;

class Tag
{
  public:
    Tag();
    ~Tag();
  private:
    Node tag;
};

#endif // TAG_H
