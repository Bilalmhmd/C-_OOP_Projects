/*============================================================================
 * Name        : Registration.cpp
 * Author      : Bilal Mohamed El-qaqei
 * Copyright   : Implemention of code by Eng : Bilal
 * Description : Registration and Login Form
 ============================================================================*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User
{
private:
	string username;
	string password;
public:
	User(string name , string pass)
	{
		username = name;
		password = pass;
	}
	string getUsername(void)
	{
		return username;
	}
	string getPassword(void)
	{
		return password;
	}
	friend class UserManger;
};

class UserManger
{
/*private:
	vector <User> users; //create object of vector*/
public:
	void RegisterUser(void)
	{
		string username;
		string password;
		cout << "\t\tEnter User Name : ";
		cin >> username;
		cout << "\t\tEnter Password : ";
		cin >> password;

		User newUser(username,password); //object from class user take the two parameter from user
		User.push_back(newUser); //built function to hold the data during the runtime

		cout <<"\t\t User Register Successfully ....."<<endl;
	}
	bool LoginUser(string name , string pass)
	{
		/*llu int because of comparison with users.size*/
		for(long long unsigned int i = 0; i< users.size() ; i++) /*users.size : built function to calculate the size of users at runtime*/
		{
			if((users[i].getUsername() == name) && (users[i].getPassword() == pass))
			{
				cout << "\t\tLogin Successfully...." << endl;
				return true;
			}
		}
		cout << "\t\tInvalid User Name or Password..." << endl;
		return false;
	}
	bool showUser()
	{
		cout <<"\t\t---Users List---" << endl;
		for(long long unsigned int i = 0; i < users.size(); i++)
		{
			cout << "\t\t" << users[i].getUsername() << endl;
			return true;
		}
		cout << "\t\t********** Users List is Empty**********" << endl;
		return false;
	}
	bool searchUser(string username)
	{
		for(long long unsigned int i = 0; i < users.size(); i++)
		{
			if(users[i].getUsername() == username)
			{
				cout << "\t\t********** User Found **********" << endl;
				return true;
			}
		}
		cout << "\t\t********** User Not Found **********" << endl;
		return false;
	}
	bool deleteUser(string username)
	{
		for(long long unsigned int i = 0 ; i < users.size(); i++)
		{
			if(users[i].getUsername() == username)
			{
				users.erase(users.begin() + i); //built function to delete user login
				cout << "\t\tUser Remove Successfully...." << endl;
				return true;
			}
		}
		cout << "\t\t********** User Not Found **********" << endl;
		return false;
	}
};



int main() {
	UserManger usermange;

	int op;
	char choice;

	do
	{
		system("cls");  // built function to clear screen after your choice
		cout << "  *****************************************************************************" << endl;
		cout << "  *****************************Registration and Login Form ********************" << endl;
		cout << "  *****************************************************************************" << endl;
		cout << "  *****************************Author: Bilal El-Qaqei *************************" << endl;
		cout << "  *****************************************************************************" << endl;
		cout << "\n\n\t\t1. Register User " << endl;
		cout << "\t\t2. Login " << endl;
		cout << "\t\t3. Show User List " << endl;
		cout << "\t\t4. Search User " << endl;
		cout << "\t\t5. Delete User " << endl;
		cout << "\t\t6. Exit " << endl;
		cout << "\t\tEnter Your Choice : ";
		cin >> op;

		switch(op)
		{
		case 1:
		{
			usermange.RegisterUser();
			break;
		}
		case 2:
		{
			string username;
			string password;
			cout << "\t\tEnter User Name : ";
			cin >> username;
			cout << "\t\tEnter Password : ";
			cin >> password;
			usermange.LoginUser(username, password);
			break;
		}
		case 3:
		{
			usermange.showUser();
			break;
		}
		case 4:
		{
			string username;
			cout << "\t\tEnter User Name : ";
			cin >> username;
			usermange.searchUser(username);
			break;
		}
		case 5:
		{
			string username;
			cout << "\t\tEnter User Name : ";
			cin >> username;
			usermange.deleteUser(username);
			break;
		}
		case 6:
		{
			exit(1); //built function to exit from program
			break;
		}

		}
		cout << "\t\tDo You Want to Continue [Yes / No] ? :";
		cin >> choice;
	}while(choice =='y' || choice == 'Y');

	return 0;
}