#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "menu.h"
#include "functions.h"

using namespace std;

void MainProgramme()
{
	int option;

	do {
		cout << "=======================" << endl;
		cout << "        OPTIONS" << endl;
		cout << "=======================" << endl;
		cout << " 1 - Create" << endl;
		cout << " 2 - Update" << endl;
		cout << " 3 - Delete" << endl;
		cout << " 4 - Search" << endl;
		cout << " 5 - Display" << endl;
		cout << " 6 - Return and save" << endl;
		cout << "========================" << endl << endl;

		cout << "Select >> ";
		
		cin >> option; // input option

		switch (option)
		{
		case 1:
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