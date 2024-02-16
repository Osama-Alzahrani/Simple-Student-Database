#include <iostream>
#include "stdClass.h"
#include "student.h"
using namespace std;

int main()
{
	int select, num;

	string name, address, contact;
	int grade, day, month, year;
	StdClass cl;
	while (1){
		
		cout << "1: add student to class\n" <<
			"2: remove student from class\n" <<
			"3: Search for student\n" <<
			"4: find students grades\n" <<
			"5: take atendence of students\n" <<
			"6: average grade\n" <<
			"7: top student\n" <<
			"8: Display class info\n"<<
			"0: Exit\n"<<
			"Select: ";
		cin >> select;
		cout << '\n';
		switch (select){
		case 1:
		{
			cin.ignore();
			cout << "Enter name of sudent" << endl;
			getline(cin, name);
			cout << "Enter address of sudent" << endl;
			getline(cin, address);
			cout << "Enter contact of sudent" << endl;
			cin >> contact;
			cout << "Enter grade of sudent" << endl;
			cin >> grade;
			while (grade > 100 || grade < 0) {cout << "Pleae enter Correct grade\n"; cin >> grade;}
			cout << "Enter birthday of sudent (day,month,year)" << endl;
			cin >> day;
			while ((day > 31) || (day < 0)) { cout << "Enter correct day\n"; cin >> day; }
			cin >> month;
			while ((month > 12) || (month < 0)) { cout << "Enter correct month\n"; cin >> month; }
			cin >> year;
			while ((year > 2023) || (year < 1900)) { cout << "Enter correct year\n"; cin >> year; }
			Student *std = new Student{ name,address,contact,grade,day,month,year};
			cl.addStd(*std);
		}
			break;
		case 2:
			cout << "Enter the id of student to remove" << endl;
			cin >> num;
			cl.removeStd(num);
			break;
		case 3:
			cout << "Enter the id of student to search" << endl;
			cin >> num;
			cl.searchStd(num);
			break;
		case 4:
			cl.overallGrade();
			break;
		case 5:
			cl.attendance();
			break;
		case 6:
			cout << "The Average of all students is: " << cl.average() << endl;
			break;
		case 7:
			cl.topStd().display();
			break;
		case 8:
			cl.displayClass();
			break;
		case 0:
			exit(0);
		default:
			break;
		}
	}

}