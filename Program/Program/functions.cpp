#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "menu.h"
#include "functions.h"

using namespace std;

string record_id[1000] = {};
string record_name[1000] = {};

void openFile()
{
	string line;
	ifstream file("Records.txt");

	if (file.is_open())
	{
		int i = 0;

		while (getline(file, line))
		{
			size_t j = line.size();
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

void createRecord()
{
	char id[100];
	char name[50];
	bool check = false;
	bool check2 = false;

	cin.ignore();

	cout << endl  << "Enter record ID >> ";

	while (!check || !check2)
	{
		cin.getline(id, 100);
		check = idCheck(id);
		check2 = idAlreadyExist(id);

		if (!check)
		{
			cout << endl << "ID must be made out of 4 symbols!" << endl << endl;
			cout << "Enter record ID >> ";
		}

		if (!check2)
		{
			cout << endl << "This ID already exists!" << endl << endl;
			cout << "Enter record ID >> ";
		}
	}

	cout << endl << "Enter record name >> ";
	cin.getline(name, 50);

	for (int i = 0; i < 1000; i++)
	{
		if (record_id[i] == "\0")
		{
			record_id[i] = id;
			record_name[i] = name;
			break;
		}
	}
}

void updateRecord(string search)
{
	char name[50];

	int counter = 0;

	for (int i = 0; i < 1000; i++)
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

void deleteRecord(string search)
{
	int count = 0;

	for (int i = 0; i < 1000; i++)
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

void searchRecord(string search)
{
	cout << "==============================" << endl;
	cout << "      Current Record(s)" << endl;
	cout << "==============================" << endl;

	int count = 0;

	for (int i = 0; i < 1000; i++)
	{
		if (record_id[i] == search)
		{
			count++;
			cout << " " << count << "        " << record_id[i] << "      " << record_name[i] << endl;
		}
	}

	if (count == 0)
	{
		cout << "No Record found!" << endl;
	}

	cout << "------------------------------" << endl << endl;
}

void displayRecord()
{
	int count = 0;

	cout << "==============================" << endl;
	cout << "      Current Record(s)" << endl;
	cout << "==============================" << endl;
	cout << " No.   |   Id   |     Name     " << endl;
	cout << "------------------------------" << endl;

	for (int i = 0; i < 1000; i++)
	{
		if (record_id[i] != "\0")
		{
			count++;
			cout << " " << count << "        " << record_id[i] << "      " << record_name[i] << endl;
		}
	}

	cout << "------------------------------" << endl;

	cout << endl;
}

void saveToFile()
{
	ofstream file;
	file.open("Records.txt");

	for (int i = 0; i < 1000; i++)
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

void mainProgram()
{
	int option;
	string input_id;
	system("CLS");
	openFile();

	do {
		cout << "=========================" << endl;
		cout << "         OPTIONS         " << endl;
		cout << "=========================" << endl << endl;
		cout << " 1 - Create Record" << endl;
		cout << " 2 - Update Record" << endl;
		cout << " 3 - Delete Record" << endl;
		cout << " 4 - Search by ID" << endl;
		cout << " 5 - Display Record(s)" << endl;
		cout << " 6 - Return and Save" << endl << endl;
		cout << "=========================" << endl << endl;

		cout << "Select >> ";
		option = inputChoiceProgramme();

		switch (option)
		{
		case 1:
			createRecord();
			system("CLS");
			break;

		case 2:
			cin.ignore();
			cout << endl << "Search by ID >> ";
			getline(cin, input_id);
			updateRecord(input_id);
			break;

		case 3:
			cin.ignore();
			cout << endl << "Delete by ID >> ";
			getline(cin, input_id);
			deleteRecord(input_id);
			break;

		case 4:
			cin.ignore();
			cout << endl << "Search by ID >> ";
			getline(cin, input_id);
			system("CLS");
			searchRecord(input_id);
			break;

		case 5:
			system("ClS");
			displayRecord();
			break;

		case 6:
			saveToFile();
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

bool idCheck(string id)
{
	if (id.size() != 4)
	{
		return false;
	}

	return true;
}

bool idAlreadyExist(string id)
{
	for (int i = 0; i < 1000; i++)
	{
		if (record_id[i] == id)
		{
			return false;
		}
		if (record_id[i] == "\0")
		{
			break;
		}
	}

	return true;
}