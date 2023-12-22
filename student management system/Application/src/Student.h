/*
 * Student.h
 *
 *  Created on: Dec 22, 2023
 *      Author: BILAL
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
using namespace std;

class Student {
private:
	int id;
	int age;
	string name;
public:
	Student(int ID, string Name,int Age);
	void setId(int ID);
	int getId();
	void setName(string Name);
	string getName();
	void setAge(int Age);
	int getAge();
	void displayStudent();
	virtual ~Student();
};

#endif /* STUDENT_H_ */
