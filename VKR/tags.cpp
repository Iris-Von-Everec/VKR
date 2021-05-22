#include "tags.h"

Tags::Tags()
{

}

Tags::~Tags()
{

}

int Tags::add_tag(QString name, QString parent, bool prime)
{
  auto it = tags_names.find(name);
  if(it != tags_names.end()) { // если имя найдено
    return -1;
  }
  else {
    Node new_tag;
    new_tag.tag_name = name;
    new_tag.has_children = false;
    new_tag.children = QVector <Node>();
    tags_names.emplace(name);
    if(prime == true) // если нет родителя
    {
      new_tag.parent = nullptr;
      tag_list.append(new_tag);
    }
    else if(prime == false)
    {
      Node* par;
      //par = find_by_name(parent);
      new_tag.parent = par;
      par->children.append(new_tag);
      par->has_children = true;
    }
  }
}

Node* Tags::find_in_child(QString tag_name, Node *where)
{
  if(where->tag_name == tag_name)
    return where;
  else if(where->has_children == true)
  {

  }
}

Node* Tags::find_by_name(QString tag_name) // nd - с какой точки искать
{
  Node *find_tag;
  bool find = false;
  /*for(auto it = tag_list.begin(); it != tag_list.end() && find == false; ++it)
  {
    if()
  } */
}

