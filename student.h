#pragma once
#include <string>
using namespace std;

class Student {
private:
    
    int ID, grade;
    string name, address, contact;
    int day, month, year;
    bool attend;
public:
    Student(string name, string address, string contact, int grade, int day, int month, int year); //Constructure 
    Student();      //Defalut Constructure
    void display();
    int getGrade();
    int getID();
    string getName();

    //Setters

    void setAttend(bool at);
};