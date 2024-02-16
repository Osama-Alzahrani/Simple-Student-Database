#include "stdClass.h"
#include <iostream>
#include <limits>

using namespace std;
StdClass::StdClass(){
	linkedlist = NULL;
	numStudent = 0;
}

void StdClass::addStd(Student& s) {
	// 
	if (MAX - 1 == numStudent) {
		cout << "Error: The class is full" << endl;
		return;
	}
	numStudent++;



	//add to list
	node* newNode = new node;
	node* temp = linkedlist;
	newNode->nextStd = NULL;
	newNode->s = &s;
	if (linkedlist == NULL) {
		
		linkedlist = newNode;
		return;
	}

	while (temp->nextStd != NULL){
		temp = temp->nextStd;
	}

	temp->nextStd = newNode;

}

void StdClass::removeStd(int n) {
	node* temp = linkedlist;
	node* old;
	old = NULL;

	while (temp != NULL)
	{
		if (temp->s->getID() == n) {
			if (temp == linkedlist)
				linkedlist = temp->nextStd;
			else
				old->nextStd = temp->nextStd;
			--numStudent;
			delete temp;
			return;
		}
		else {
			old = temp;
			temp = temp->nextStd;
		}
	}
	cout << "We can't find the student\n";
}



double StdClass::average() {
	//int* grades =new int(numStudent);
	auto grades = make_unique<int[]>(numStudent);
	node* temp = linkedlist;
	int i = 0,sum=0;
	
	while (temp != NULL)
	{
		grades[i] = temp->s->getGrade();
		i++;
		temp = temp->nextStd;
		
	}

	for (int j = 0; j < numStudent; j++)
	{
		sum+=grades[j];
	}
	return (sum / numStudent);
}

Student& StdClass::topStd() {
	Student* std = new Student[numStudent];
	node* temp = linkedlist;
	int i = 0, top = INT_MIN,stTop=0;
	
	while (temp != NULL)
	{
		std[i] = *temp->s;
		i++;
		temp = temp->nextStd;
	}

	for (int j = 0; j < numStudent; j++)
	{
		if (std[j].getGrade() > top) {
			top = std[j].getGrade();
			stTop = j;
		}
	}
	return std[stTop];
	
}


void StdClass::attendance(){
	node* front = NULL;
	node* rear = new node;
	node* temp = linkedlist;

	if (rear == NULL) {
		cout << "Error memory is full" << endl;
		return;
	}
	else if (temp == NULL) {
		cout << "The linked list is empty" << endl;		// TODO LSIT :
	}

	while (temp != NULL)
	{
		if (front == NULL) {
			rear = front = temp;
		}
		else {
			rear->nextStd = temp;
			rear = rear->nextStd;
		}

		temp = temp->nextStd;
	}
	
	for (temp = front;  temp !=NULL ; temp=temp->nextStd)
	{
		bool attend;
		cout << "ID: " << temp->s->getID() << "\nStudent name: " << temp->s->getName() << endl;
		cout << "Enter the student's attendance status:\n" << "1. Present.\n" << "0. Absent" << endl;
		cin >> attend; 
		temp->s->setAttend(attend);
	}
}

void StdClass::overallGrade(){
	node* top = NULL;
	node* temp = linkedlist;
	

	if (temp == NULL) {
		cout << "Error memory is full" << endl;
		return;
	}
	while (temp != NULL)
	{
		node* stackTemp = new node;
		stackTemp->s = temp->s;

		stackTemp->nextStd = top;
		top = stackTemp;

		temp = temp->nextStd;
	}

	while (top != NULL)
	{
		cout << "ID: " << top->s->getID() << "\tStudent name: " << top->s ->getName() << "\tGrade: " << top->s->getGrade()<<endl;
		top = top->nextStd;
	}
	cout << "The average of student is: "<< average() << endl;
}

void StdClass::searchStd(int n)
{
	node* temp = linkedlist;
	while (temp!=NULL)
	{
		if (n == temp->s->getID()) {
			cout << "Student is found:\n";
			temp->s->display();
			return;
		}
		
		temp = temp->nextStd;
	}

	cout << "Student not found in database\n";
}

void StdClass::displayClass() {
	node* temp = linkedlist;

	cout << "Class information" << endl;
	while (temp !=NULL)
	{
		temp->s->display();
		temp = temp->nextStd;
		cout << "\n\n";
	}
}