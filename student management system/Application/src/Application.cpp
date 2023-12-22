//============================================================================
// Name        : Application.cpp
// Author      : Bilal Mohamed El-Qaqei
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

/******************** Header File ********************/
#include "Student.h"


//Create function update Student record
void updateStudent(vector<Student> & students){

	string sname;

	bool found = false;

	int choice;

	cout<<"\t\tEnter Name to Update Record :";

	cin.ignore();

	getline(cin,sname);

	for(int i = 0; i<students.size();i++)
	{

		if(students[i].getName()==sname)
		{
			found = true;
			cout<<"\t\t---Student Found -----"<<endl;
			cout<<"\t\t 1. Update Id Number "<<endl;
			cout<<"\t\t 2. Update Name "<<endl;
			cout<<"\t\t 3. Update Age "<<endl;
			cout<<"\t\tEnter Your Choice : ";
			cin>>choice;

			switch(choice){
				case 1:
				{
					int id;
					cout<<"\t\tEnter New Id Number: ";
					cin>>id;
					students[i].setId(id);
					break;
				}
				case 2:
				{
					string name;
					cout<<"\t\tEnter New Name :";
					cin.ignore();
					getline(cin,name);
					students[i].setName(name);
					break;
				}
				case 3:
				{
					int age;
					cout<<"\t\tEnter New Age :";
					cin>>age;
					students[i].setAge(age);
					break;
				}
				default: cout<<"\t\tInvalid Number"<<endl;
			}
		}
		if(!found) /*for readability*/
		{
			cout<<"\t\tRecord Not Found"<<endl;
			return;
		}
	}
}

//create function to search student in list
void SearchStudent(vector<Student>& students){

	int id;

	cout<<"\t\tEnter Id Number :";

	cin>>id;



	for(int i = 0; i<students.size();i++)
	{
		if(students[i].getId() == id)
		{
			cout<<"\t\t--------Student Found ------------"<<endl;
			students[i].displayStudent();
			return;
		}
	}
}

//create function to show all list of  student
void DisplayAllStudent(vector<Student>& students){

	if(students.empty())
	{
		cout<<"\t\t No Student Found "<<endl;
		return;
	}
	for(int i = 0; i<students.size();i++)
	{
		students[i].displayStudent();
		cout<<"\t\t--------------------";
		cout<<endl;
	}
}

//create function to add new student
void addNewStudent(vector<Student> &students){

	int id,age;

	string name;

	cout<<"\n\t\tEnter Id Number :";

	cin>>id;

	//check if student already exit
	for(int i = 0; i<students.size();i++){
		if(students[i].getId() == id)
		{
			cout<<"\t\tStudent Already Exit"<<endl;
			return;
		}
	}
	cout<<"\n\t\tEnter Name : ";
	cin>>name;
	cout<<"\n\t\tEnter Age : ";
	cin>>age;
	Student newStudent(id,name,age);
	students.push_back(newStudent);
}

//create function to delete student in list
void deleteStudent(vector<Student>& students)
{
	string name;
	cout<<"Enter Name to Delete :";
	cin.ignore();
	getline(cin,name);

	for(int i = 0; i<students.size();i++)
	{
		if(students[i].getName() == name)
		{
			students.erase((students.begin()+i));
			cout<<"\t\tStudent Remove Successfully"<<endl;
		}
	}
}

int main()
{
	vector <Student> students;
	students.push_back(Student(1,"Bilal",23));
	char choice;

	do{
		system("cls");

		int op;

		cout<<"\n\t\t----------------------------------------------------------------";

		cout<<"\n\t\t****************** Student Management System ******************";

		cout<<"\n\t\t----------------------------------------------------------------";

		cout<<"\n\t\t 1. Add New Student"<<endl;

		cout<<"\t\t 2. Display All Student "<<endl;

		cout<<"\t\t 3. Search Student"<<endl;

		cout<<"\t\t 4. Update Student"<<endl;

		cout<<"\t\t 5. Delete Student "<<endl;

		cout<<"\t\t 6. Exit"<<endl;

		cout<<"\t\t Enter Your Choice : ";

		cin>>op;

		switch(op)
		{
			case 1:
				cout<<"\n\t\t----------------------------------------------------------------\n";
				addNewStudent(students);
				break;
			case 2:
				cout<<"\n\t\t----------------------------------------------------------------\n";
				DisplayAllStudent(students);
				break;
			case 3:
				cout<<"\n\t\t----------------------------------------------------------------\n";
				SearchStudent(students);
				break;
			case 4:
				cout<<"\n\t\t----------------------------------------------------------------\n";
				updateStudent(students);
				break;
			case 5:
				cout<<"\n\t\t----------------------------------------------------------------\n";
				 deleteStudent(students);
				 break;
				 cout<<"\n\t\t----------------------------------------------------------------\n";
			case 6:	exit(1);
			default: cout<<"\t\tInvalid Number "<<endl;
		}
		   cout<<"\t\tDo You Want to Continue [Yes/No] ? :";
		   cin>>choice;

	}while(choice == 'y'||choice=='Y');
}
