#include <string>
#include <iostream>
#include "messages.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void errorNote(std::string note)
{
	system("cls");
	std::cout << "!!!!!!!!!!!!!!!" << std::endl << std::endl;
	std::cout << note << std::endl << std::endl;
	std::cout << "!!!!!!!!!!!!!!!";
	Sleep(2000);
	system("cls");
}

void notification(int duration, std::string note)
{
	system("cls");
	std::cout << std::endl << std::endl;
	std::cout << note << std::endl << std::endl;
	Sleep(duration);
	system("cls");
}
