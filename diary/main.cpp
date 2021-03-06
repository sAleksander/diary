#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "messages.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Menus

void encripting(string pass,bool encode, string line)
{
	int key = 0;

	for (int i = 0; i < pass.length(); i++)
	{
		key += pass[i];
	}

	if (encode == true)
	{
		for (int i = 0; i < line.length(); i++)
		{
			line[i] = line[i] + key;
		}
	}

	else if (encode == false)
	{
		for (int i = 0; i < line.length(); i++)
		{
			line[i] = line[i] - key;
		}
	}

}

int fileWrite()
{
	string fileName;
	string content;
	fstream fileToSave;

	system("cls");
	
	cout << "File header : ";

	cin >> fileName;

	system("cls");

	fileToSave.open(fileName + ".txt", ios::out);

	cout << fileName << endl << endl;
	
	getline(cin, content);
	getline(cin, content);

	fileToSave << content;

	fileToSave.close();
	
	return 0;
}

int fileRead()
{
	fstream fileToRead;
	string fileName;
	system("cls");
	cout << "type file name : ";
	cin >> fileName;
	fileName = fileName + ".txt";

	fileToRead.open(fileName, ios::in);

	if (fileToRead.good())
	{
		system("cls");
		string line;
		while (!fileToRead.eof())
		{
			getline(fileToRead, line);
			cout << line << endl;
		}

		system("pause");

		return 0;
	}
	else
	{
		notification(2000, "Couldn`t find file");

		return 0;
	}

}


int workspace()
{
	int choice;

	while (true)
	{
		system("cls");
		choice = 0;
		cout << "1. New file" << endl;
		cout << "2. Read file" << endl;
		cout << "3. Log out" << endl;
		choice = _getch();


		if (choice == 51)
		{
			notification(1000, "Succesfully logged out!");

			return 0;
		}

		else if (choice == 50)
		{
			fileRead();
		}

		else if (choice == 49)
		{
			fileWrite();
		}

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
					notification(1000, "Logged in!");
					workspace();
					return 0;
				}
				else
				{
					notification(1000, "Password incorrect!");
					return 0;
				}
			}
		}

		notification(1000, "Couldn`t find this user, try again");

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

	notification(1000, "REGISTERED!");
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
