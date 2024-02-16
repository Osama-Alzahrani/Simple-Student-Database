#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <iostream>
int IDs = 1;
using namespace std;


//Defalut Constructure
Student::Student() {

	this->name = "None";
	this->address = "None";
	this->contact = "0000";
	this->grade = 0;
	this->day = 0;
	this->month = 0;
	this->year = 0;
	attend = 0;
	this->ID = 0;
}

//Constructure
Student::Student(string name, string address, string contact, int grade, int day, int month, int year) {
	this->name = name;
	this->address = address;
	this->contact = contact;
	this->grade = grade;
	this->day = day;
	this->month = month;
	this->year = year;
	attend = 0;
	this->ID=IDs++;
}

//Display Student Info
void Student::display() {
	cout <<"ID: "<< ID << "\nName: " << name << "\nAddress: " << address <<
		"\nContact Information: " << contact << "\nDate of birth: "<< day <<
		"/" << month << "/" << year << "\nGrade: " << grade <<"\nAttendence: "<< attend << endl;
}
//Get Student Name
string Student::getName() { return name; }

//Get Student Grade
int Student::getGrade() { return grade; }

//Get student ID
int Student::getID() { return ID; }

//set attend

void Student::setAttend(bool at) {
	attend = at;
}

