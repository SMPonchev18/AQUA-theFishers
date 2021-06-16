#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "menu.h"
#include "functions.h"

using namespace std;


string record_id[100] = {};
string record_name[100] = {};

void CreateRecord()
{
	char id[4];
	char name[50];

	cin.ignore();

	cout << "Enter record ID >> ";
	cin.getline(id, 4);

	cout << "Enter record name >> ";
	cin.getline(name, 50);

	for (int i = 0; i < 100; i++)
	{
		if (record_id[i] == "\0")
		{
			record_id[i] = id;
			record_name[i] = name;
			break;
		}
	}
}

void MainProgramme()
{
	int option;
	system("CLS");

	do {
		cout << "=======================" << endl;
		cout << "        OPTIONS" << endl;
		cout << "=======================" << endl << endl;
		cout << " 1 - Create" << endl;
		cout << " 2 - Update" << endl;
		cout << " 3 - Delete" << endl;
		cout << " 4 - Search" << endl;
		cout << " 5 - Display" << endl;
		cout << " 6 - Return and save" << endl << endl;
		cout << "========================" << endl;

		cout << endl << "Select >> ";
		option = inputChoiceProgramme();

		switch (option)
		{
		case 1:
			CreateRecord();
			system("CLS");
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			break;
		}
	} while (option);
}

int inputChoiceProgramme()   // Allows the user to input their operation of choice
{
	int user_choice;
	bool check_num = false;

	while (check_num == false)
	{
		if (cin >> user_choice)
		{
			if (user_choice > 6 || user_choice < 1) // Invalid input
			{
				cout << endl << "You entered an invalid operation. Please try again." << endl << endl;
				cout << "Select >> ";
				check_num = false;
			}

			else    // Valid input
			{
				check_num = true;
			}
		}

		else    // The user entered a character
		{
			cout << endl << "You entered an invalid operation. Please try again." << endl << endl;
			cout << "Select >> ";
			cin.clear();
			cin.ignore(1000, '\n');
			check_num = false;
		}
	}

	return user_choice;
}