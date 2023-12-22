/*
 * Student.cpp
 *
 *  Created on: Dec 22, 2023
 *      Author: BILAL
 */

#include "Student.h"
#include <iostream>
 // Constructor
Student::Student(int ID, string Name,int Age): id(ID),name(Name),age(Age)
{
		//Initialization
}


void Student::setId(int ID)
{
	id = ID;
}

int Student::getId(void)
{
	return id;
}

void Student::setName(string Name)
{
	name = Name;
}

string Student::getName()
{
	return name;
}

void Student::setAge(int Age)
{
	age = Age;
}

int Student::getAge()
{
	return age;
}

void Student::displayStudent()
{
	cout<<"\t\tID Number : "<<id<<endl;

	cout<<"\t\tName : "<<name<<endl;

	cout<<"\t\tAge : "<<age<<endl;
}


Student::~Student() {
	// TODO Auto-generated destructor stub
}

