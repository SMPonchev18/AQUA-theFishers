#include <iostream>
#include <iomanip>
#include "menu.h"
#include "functions.h"

using namespace std;

void printMenu()
{

    cout << "==============================" << endl;
    cout << "             MENU             " << endl;
    cout << "==============================" << endl;
    cout << "                              " << endl;
    cout << " 1) Records                   " << endl;
    cout << " 2) Endangered species        " << endl;
    cout << " 3) How to use our program    " << endl;
    cout << " 4) Team Information          " << endl;
    cout << " 5) Exit                      " << endl;
    cout << "                              " << endl;
    cout << "==============================" << endl;

    cout << endl << "Select >> ";

    choice(inputChoice());
}

int inputChoice()
{
    int user_choice;
    bool check_num = false;

    while (check_num == false)
    {
        if (cin >> user_choice)
        {
            if (user_choice > 5 || user_choice < 1) // Invalid input
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
            cout << endl << "You entered an invalid operation. Please try again." << endl;
            cout << "Select >> ";
            cin.clear();
            cin.ignore(1000, '\n');
            check_num = false;
        }
    }

    return user_choice;
}

void choice(int user_choice)
{
    system("CLS");

    switch (user_choice)
    {
    case 1:
        MainProgramme();
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;
    }
}