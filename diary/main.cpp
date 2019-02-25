#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Menus

int loginUser()
{
	string login;
	string password;
	string loginInFile;
	string passwordInFile;

	bool tick = true;

	fstream loginFile;

	loginFile.open("lp.txt", ios::in);
	if (loginFile.good())
	{
		while (!loginFile.eof())
		{
			getline(loginFile, loginInFile);
			getline(loginFile, passwordInFile);

			if (loginInFile == login)
			{
				if (passwordInFile == password)
				{
					cout << "Loged in!";
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
	}

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
	logPass << login << endl << password;

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
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Menus end

int main()
{
	mainMenu();
	return 0;
}
