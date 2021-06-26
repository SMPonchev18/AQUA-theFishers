#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "menu.h"
#include "functions.h"

using namespace std;

string record_id[1000] = {};
string record_name[1000] = {};

void openFile()	// Starts reading the Records.txt file so it can input information into it
{
	string line;
	ifstream file("Records.txt");

	if (file.is_open())	// The file is successfully opened
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

	else	// There is a problem with the file
	{
		cout << "Enable to open the file!" << endl;
	}
}

void createRecord()
{
	char id[100];
	char name[50];
	bool check_symbols = false;
	bool check_existance = false;

	cin.ignore();

	cout << endl  << "Enter record ID >> ";

	while (!check_symbols || !check_existance)	// Checks the entered ID
	{
		cin.getline(id, 100);
		check_symbols = checkIdLenght(id);
		check_existance = checkExistence(id);

		if (!check_symbols)		// ID isn't made out of 4 symbols
		{
			cout << endl << "ID must be made out of 4 symbols!" << endl << endl;
			cout << "Enter record ID >> ";
		}

		if (!check_existance)	// ID already exists
		{
			cout << endl << "This ID already exists!" << endl << endl;
			cout << "Enter record ID >> ";
		}
	}

	cout << endl << "Enter record name >> ";
	cin.getline(name, 50);

	for (int i = 0; i < 1000; i++)	// Adds the record information into the global arrays
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

	if (counter == 0)	// The user entered a non-existing ID
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

	if (count == 0)	// The user entered a non-existing ID
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
		if (record_id[i] == search)	// ID matches a records ID
		{
			count++;
			cout << " " << count << "        " << record_id[i] << "      " << record_name[i] << endl;
		}
	}

	if (count == 0)	// The user entered a non-existing ID
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
		if (record_id[i] == "\0")	// No more records left to be written in the file
		{
			break;
		}

		else	// Writes the new record into the file 
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
			if (user_status == "Administrator" || user_status == "administrator" || user_status == "Assistant" || user_status == "assistant")
			{
				createRecord();
				system("CLS");
			}

			else
			{
				system("CLS");
				cout << "Your authority isn't high enough to do this operation!" << endl << endl;
			}

			break;

		case 2:
			if (user_status == "Administrator" || user_status == "administrator" || user_status == "Assistant" || user_status == "assistant")
			{
				cin.ignore();
				cout << endl << "Search by ID >> ";
				getline(cin, input_id);
				updateRecord(input_id);
			}

			else
			{
				system("CLS");
				cout << "Your authority isn't high enough to do this operation!" << endl << endl;
			}

			break;

		case 3:
			if (user_status == "Administrator" || user_status == "administrator" || user_status == "Assistant" || user_status == "assistant")
			{
				cin.ignore();
				cout << endl << "Delete by ID >> ";
				getline(cin, input_id);
				deleteRecord(input_id);
			}

			else
			{
				system("CLS");
				cout << "Your authority isn't high enough to do this operation!" << endl << endl;
			}

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

bool checkIdLenght(string id)		// Checks if ID is made out of 4 symbols
{
	if (id.size() != 4)	
	{
		return false;
	}

	return true;
}

bool checkExistence(string id)	// Checks if ID already exists
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