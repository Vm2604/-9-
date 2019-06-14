#include "pch.h"
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

struct timetable
{
	string name, secondname, lastname,position;
	int  day, month, year, minutes[1], hours[1], minutes_end[1], hours_end[1];
};

void menu(timetable *time, int number);

void Data_Input(timetable *time, int number)
{
	system("cls");
	for (size_t i = 0; i < number; i++)
	{
		std::cout << "Имя Сотрудника: " << "\n";
		std::cin >> time[i].name;
		std::cout << "\n";

		std::cout << "Отчество Сотрудника: " << "\n";
		std::cin >> time[i].secondname;
		std::cout << "\n";

		std::cout << "Фамилия Сотрудника: " << "\n";
		std::cin >> time[i].lastname;
		std::cout << "\n";


		std::cout << "Должность: " << "\n";
		std::cin >> time[i].position;
		std::cout << "\n";


		std::cout << "День: " << "\n";
		std::cin >> time[i].day;
		std::cout << "\n";
		std::cout << "Месяц: " << "\n";
		std::cin >> time[i].month;
		std::cout << "\n";
		std::cout << "Год: " << "\n";
		std::cin >> time[i].year;
		std::cout << "\n";

		std::cout << "Прибытие на работу" << "\n";

		std::cout << "Минуты (первый экзамен): " << "\n";
		std::cin >> time[i].minutes[0];
		std::cout << "\n";
		std::cout << "Час (первый экзамен)" << "\n";
		std::cin >> time[i].hours[0];
		std::cout << "\n";
		

		std::cout << "Уход с работы" << "\n";

		std::cout << "Минуты (первый экзамен): " << "\n";
		std::cin >> time[i].minutes_end[0];
		std::cout << "\n";
		std::cout << "Час (первый экзамен)" << "\n";
		std::cin >> time[i].hours_end[0];
		std::cout << "\n";
		
	}
	menu(time, number);
}

void Data_Output(timetable *time, int number)
{
	system("cls");
	for (size_t i = 0; i < number; i++)
	{
		std::cout << "Имя Сотрудника: " << "\n";
		std::cout << time[i].name;
		std::cout << "\n";

		std::cout << "Отчество Сотрудника: " << "\n";
		std::cout << time[i].secondname;
		std::cout << "\n";

		std::cout << "Фамилия Сотрудника: " << "\n";
		std::cout << time[i].lastname;
		std::cout << "\n";

		

		std::cout << "Должность: " << "\n";
		std::cout << time[i].position;
		std::cout << "\n";

		std::cout << "День: " << "\n";
		std::cout << time[i].day;
		std::cout << "\n";

		std::cout << "Месяц: " << "\n";
		std::cout << time[i].month;
		std::cout << "\n";

		std::cout << "Год: " << "\n";
		std::cout << time[i].year;
		std::cout << "\n";

		std::cout << "Прибытие на работу." << "\n";

		std::cout << "Минуты (пришел): " << "\n";
		std::cout << time[i].minutes[0];
		std::cout << "\n";
		

		std::cout << "Час (пришел)" << "\n";
		std::cout << time[i].hours[0];
		std::cout << "\n";
		

		std::cout << "Уход с работы." << "\n";

		std::cout << "Минуты (ушел): " << "\n";
		std::cout << time[i].minutes_end[0];
		std::cout << "\n";
		

		std::cout << "Час (ушел)" << "\n";
		std::cout << time[i].hours_end[0];
		std::cout << "\n";
		
	}
	menu(time, number);
}

void Data_Save(timetable *time, int number)
{
	std::cout << "Выберите название файла" << "\n";
	string choice;
	std::cin >> choice;

	ofstream database;
	database.open(choice);

	for (size_t i = 0; i < number; i++)
	{
		database << time[i].name << " ";
		database << time[i].secondname << " ";
		database << time[i].lastname << " ";
		database << time[i].position << " ";
		database << time[i].day << " ";
		database << time[i].month << " ";
		database << time[i].year << " ";
		database << time[i].minutes[0] << " ";
		database << time[i].hours[0] << " ";
		database << time[i].minutes_end[0] << " ";
		database << time[i].hours_end[0] << " ";
	}

	std::cout << "Успешная запись!" << "\n";
	database.close();
	menu(time, number);
}

void Data_New_Save(timetable *time, int number, string file_name)
{
	std::cout << "Создание файла " << file_name << "\n";
	ofstream database;
	database.open(file_name);

	for (size_t i = 0; i < number; i++)
	{
		database << time[i].name << " ";
		database << time[i].secondname << " ";
		database << time[i].lastname << " ";
		database << time[i].position << " ";
		database << time[i].day << " ";
		database << time[i].month << " ";
		database << time[i].year << " ";
		database << time[i].minutes[0] << " ";
		database << time[i].hours[0] << " ";
		database << time[i].minutes_end[0] << " ";
		database << time[i].hours_end[0] << " ";
	}

	std::cout << "Успешная запись!" << "\n";
	database.close();
}

void Data_Read(timetable *time, int number)
{
	system("cls");
	std::cout << "Выберите название файла" << "\n";
	string choice;
	std::cin >> choice;

	ifstream database;
	database.open(choice);

	for (size_t i = 0; i < number; i++)
	{
		database >> time[i].name;
		database >> time[i].secondname;
		database >> time[i].lastname;	
		database >> time[i].position;
		database >> time[i].day;
		database >> time[i].month;
		database >> time[i].year;
		database >> time[i].minutes[0];
		database >> time[i].hours[0];
		database >> time[i].minutes_end[0];
		database >> time[i].hours_end[0];
	}

	std::cout << "Успешное считывание" << "\n";
	database.close();
	menu(time, number);
}







void menu(timetable *time, int number)
{

	std::cout << "Сделайте выбор:" << "\n";
	std::cout << "1. Внести данные" << "\n";
	std::cout << "2. Считать данные" << "\n";
	std::cout << "3. Вывести на экран данные" << "\n";
	std::cout << "4. Сохранить текущие данные" << "\n";

	int choice = 0;

	std::cin >> choice;
	if (choice == 1)
	{
		Data_Input(time, number);
	}
	else if (choice == 2)
	{
		Data_Read(time, number);
	}
	else if (choice == 3)
	{
		Data_Output(time, number);
	}
	else if (choice == 4)
	{
		Data_Save(time, number);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	std::cout << "Начало работы." << "\n";
	std::cout << "Выберите количество записей" << "\n";

	int number = 0;

	std::cin >> number;

	timetable *time = new timetable[number];
	menu(time, number);
}