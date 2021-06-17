#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "menu.h"
#include "functions.h"

using namespace std;

string record_id[100] = {};
string record_name[100] = {};

void OpenFile()
{
	string line;
	ifstream file("Records.txt");

	if (file.is_open())
	{
		int i = 0;

		while (getline(file, line))
		{
			int j = line.size();
			record_id[i] = line.substr(0, 4);
			record_name[i] = line.substr(5, j - 5);
			i++;
		}
	}

	else
	{
		cout << "Enable to open the file!" << endl;
	}
}

void CreateRecord()
{
	char id[5];
	char name[50];

	cin.ignore();

	cout << "Enter record ID >> ";
	cin.getline(id, 5);

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

void UpdateRecord(string search)
{
	char name[50];

	int counter = 0;

	for (int i = 0; i < 100; i++)
	{
		if (record_id[i] == search)
		{
			counter++;

			cout << "Enter new record name >> ";
			cin.getline(name, 50);
			system("CLS");

			record_name[i] = name;

			cout << "Update successful!" << endl;
			break;
		}
	}

	if (counter == 0)
	{
		system("CLS");
		cout << "Record doesn't exist!" << endl;
	}
}

void DeleteRecord(string search)
{
	int count = 0;

	for (int i = 0; i < 100; i++)
	{
		if (record_id[i] == search)
		{
			count++;

			record_name[i] = "";
			record_id[i] = "";

			system("CLS");

			cout << "Successfully deleted!" << endl;
			break;
		}
	}

	if (count == 0)
	{
		system("CLS");
		cout << "ID doesn't exist!" << endl;
	}
}

void SearchRecord(string search)
{
	cout << "==============================" << endl;
	cout << "      Current Record(s)" << endl;
	cout << "==============================" << endl;

	int count = 0;

	for (int i = 0; i < 100; i++)
	{
		if (record_id[i] == search)
		{
			count++;
			cout << " " << count << "        " << record_id[i] << "        " << record_name[i] << endl;
		}
	}

	if (count == 0)
	{
		cout << "No Record found!" << endl;
	}

	cout << "------------------------------" << endl << endl;
}

void DisplayRecord()
{
	int count = 0;

	cout << "==============================" << endl;
	cout << "      Current Record(s)" << endl;
	cout << "==============================" << endl;
	cout << " No.   |   Id   |     Name     " << endl;
	cout << "------------------------------" << endl;

	for (int i = 0; i < 100; i++)
	{
		if (record_id[i] != "\0")
		{
			count++;
			cout << " " << count << "        " << record_id[i] << "        " << record_name[i] << endl;
		}
	}

	cout << "------------------------------" << endl;

	cout << endl;
}

void SaveToFile()
{
	ofstream file;
	file.open("Records.txt");

	for (int i = 0; i < 100; i++)
	{
		if (record_id[i] == "\0")
		{
			break;
		}

		else
		{
			file << record_id[i] + "," + record_name[i] << endl;
		}
	}
}

void MainProgram()
{
	int option;
	string input_id;
	system("CLS");
	OpenFile();

	do {
		cout << "=======================" << endl;
		cout << "        OPTIONS" << endl;
		cout << "=======================" << endl << endl;
		cout << " 1 - Create" << endl;
		cout << " 2 - Update" << endl;
		cout << " 3 - Delete" << endl;
		cout << " 4 - Search by ID" << endl;
		cout << " 5 - Display" << endl;
		cout << " 6 - Return and save" << endl << endl;
		cout << "=======================" << endl << endl;

		cout << "Select >> ";
		option = inputChoiceProgramme();

		switch (option)
		{
		case 1:
			CreateRecord();
			system("CLS");
			break;

		case 2:
			cin.ignore();
			cout << endl << "Search by ID >> ";
			getline(cin, input_id);
			UpdateRecord(input_id);
			break;

		case 3:
			cin.ignore();
			cout << endl << "Delete by ID >> ";
			getline(cin, input_id);
			DeleteRecord(input_id);
			break;

		case 4:
			cin.ignore();
			cout << endl << "Search by ID >> ";
			getline(cin, input_id);
			system("CLS");
			SearchRecord(input_id);
			break;

		case 5:
			system("ClS");
			DisplayRecord();
			break;

		case 6:
			SaveToFile();
			system("CLS");
			printMenu();
			break;
		}
	} while (option);
}

int inputChoiceProgramme()
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