//
// Created by Софья on 26.04.2024.
//

#include <string>
#include <map>
#include <memory>
#include <algorithm>

using namespace std;
//Напишите класс на C++, который реализует простую систему управления базой данных студентов.
//Каждый студент представлен структурой Student, содержащей следующие поля: id (целочисленный идентификатор),
//name (строка с именем студента), и age (целочисленный возраст студента). Ваш класс должен обеспечивать следующие возможности:
//
//- Добавление нового студента в базу данных.
//
//- Удаление студента по идентификатору.
//
//- Получение информации о студенте по идентификатору.
//
//- Используйте умный указатель std::shared_ptr для хранения и управления объектами студентов в
//контейнере внутри класса (например, std::vector или std::map).

struct Student{
    Student(Student &s) : id(s.id), name(s.name), age(s.age) {}
    int id;
    string name;
    int age;
};

class DBMS{
private:
    map<int, shared_ptr<Student>> students;
public:
    void addStudent(Student &s){
        Student *scopy = new Student(s);
        students.insert(make_pair(scopy->id,make_shared<Student>(*scopy)));
    }

    void deleteStudent(Student &s){
        shared_ptr<Student> toDelete = students[s.id];
        students.erase(s.id);
        toDelete.reset();
    }

    Student getStudent(int id){
        return *(students[id]);
    }
};