#pragma once
#include "student.h"
#include <string>
using namespace std;
int const MAX = 50; //Maximum Student in the Class (Cource)

class StdClass {
private:
    int numStudent; //Current Number of student

    //linked list
    struct node {
        Student* s;     // make class student member of node struct as Data
        node* nextStd;  // Next student in the linked list
    }*linkedlist;

public:
    StdClass();                 //Constructor 
    void addStd(Student& s);    //Add studnet to the class                  =====> Linked list
    void removeStd(int n);      //Remove studnet from class                 =====> Linked list
    void searchStd(int n);  //Search for student in the class               =====> Linked list
    void attendance();          //Show the attendence of the student        =====> Queue
    double average();           //Get average grade of the class            =====> Array
    Student& topStd();          //Get top student grade in the class        =====> Array
    void overallGrade();        //Display all student grades of the class   =====> Stack
    void displayClass();
};