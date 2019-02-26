#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Menus
void errorNote(string note)
{
	system("cls");
	cout << "!!!!!!!!!!!!!!!" << endl << endl;
	cout << note << endl << endl;;
	cout << "!!!!!!!!!!!!!!!";
	Sleep(2000);
	system("cls");
}


int workSpace()
{
	while (true)
	{

	}

	errorNote("something wron in a workspace");
	return 0;
}


int loginUser()
{
	string login;
	string password;
	string loginInFile;
	string passwordInFile;

	fstream loginFile;

	loginFile.open("lp.txt", ios::in);
	if (loginFile.good())
	{
		cout << "Type login : ";
		cin >> login;
		cout << "Type password : ";
		cin >> password;
		system("cls");

		while (!loginFile.eof())
		{
			getline(loginFile, loginInFile);
			getline(loginFile, passwordInFile);


			if (loginInFile == login)
			{
				if (passwordInFile == password)
				{
					cout << "Logged in!";
					Sleep(1000);
					system("cls");
					return 0;
				}
				else
				{
					cout << "Password incorrect!" << endl;
					Sleep(1000);
					system("cls");
					return 0;
				}
			}
		}

		cout << "Couldn`t find this user, try again";
		Sleep(1000);
		loginFile.close();
		return 0;
	}

	errorNote("ls.txt read failure!");
	return 0;
}

void registration()
{
	string login;
	string password;
	fstream logPass;
	logPass.open("lp.txt", ios::app);

	cout << "Type your login : ";
	cin >> login;
	cout << "Type your password : ";
	cin >> password;
	logPass << login << endl << password << endl;

	logPass.close();
	system("cls");
	cout << "REGISTERED!";
	Sleep(1000);
	system("cls");
}

int mainMenu()
{
	int choice = 0;
	while (true)
	{
		system("cls");
		choice = 0;
		cout << "1. Sign in" << endl;
		cout << "2. Register" << endl;
		cout << "3. End" << endl;

		choice = _getch();

		if (choice == 51)
		{
			return 0;
		}

		if (choice == 50)
		{
			system("cls");
			registration();
		}

		if (choice == 49)
		{
			system("cls");
			loginUser();
		}
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Menus end

int main()
{
	mainMenu();
	return 0;
}
