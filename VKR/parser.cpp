#include "parser.h"

Parser::Parser()
{

}

/* кусок кода с тестом парсинга json
json_path = PRO_FILE_PWD;
json_path.append("/test1.json");
qDebug() << json_path;
write_json();
read_json();
check_sum_of_files(); */

/*void Manager::read_json()
{
  QString value;
  json_file.setFileName(json_path);
  json_file.open(QIODevice::ReadOnly | QIODevice::Text);
  value = json_file.readAll();
  json_file.close();
  QJsonDocument document = QJsonDocument::fromJson(value.toUtf8());
  QJsonObject json_obj = document.object();
  QJsonValue json_value = json_obj.value("Tag_1");
  if (json_value.isObject())
  {
      QJsonObject file_obj = json_value.toObject();
      QJsonValue file_value = file_obj.value("File Name 1");
      if (file_value.isObject())
        {
          QJsonObject final_obj = file_value.toObject();
          hash_sum = final_obj["Hash sum"].toString();
          QString file_path = final_obj["Path"].toString();
          QString file_type = final_obj["type"].toString();
      //    qDebug() << hash_sum << file_path << file_type << "\n";
        }
      else
        qDebug() << "Не считалось 2\n";
  }
  else
    qDebug() << "Не считалось 1\n";
}

void Manager::write_json()
{
  QJsonObject json_obj, json_tagObj, json_subObj; // пока что без иерархии
  json_subObj.insert("Hash sum", "qwerty12345");
  json_subObj.insert("Path", PRO_FILE_PWD);
  json_subObj.insert("type", ".json");
  json_tagObj.insert("File Name 1", json_subObj);
  json_obj.insert("Tag_1", json_tagObj);
  json_subObj.insert("Hash sum", "zxcmd5sum");
  json_subObj.insert("Path", PRO_FILE_PWD);
  json_subObj.insert("type", ".txt");
  json_tagObj.insert("File Name 2", json_subObj);
  json_obj.insert("Tag_1", json_tagObj);
  //QJsonArray numbersArray;x
 // numbersArray.push_back("1");
  //numbersArray.push_back("2");
 // numbersArray.push_back("3");
  QJsonDocument document(json_obj);
  json_string = document.toJson(QJsonDocument::Indented);
  //Записываем данные в файл
  json_file.setFileName(json_path);
  json_file.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream stream(&json_file);
  stream << json_string;
  json_file.close();
} */
