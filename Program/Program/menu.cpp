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
        MainProgram();
        break;

    case 2:
        printEndangeredSpecies();
        break;

    case 3:
        break;

    case 4:
        printTeamInformation();
        break;

    case 5:
        system("CLS");
        cout << "Thank you for using our program! :)" << endl; 
        exit(0);
    }
}

void printEndangeredSpecies()
{
    cout << "=============================================================" << endl;
    cout << "                      PROTECTED SPECIES                      " << endl;
    cout << "=============================================================" << endl;
    cout << "            ANIMAL            |            STATUS            " << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "          Sea Turtle          |          Endangered" << endl;
    cout << "            Vaquita           |     Critically Endangered" << endl;
    cout << "          White Shark         |          Endangered" << endl;
    cout << "            Dugong            |          Vulnerable" << endl;
    cout << "        Humphead Wrasse       |          Endangered" << endl;
    cout << "            Whales            |          Endangered" << endl;
    cout << "          Sea Lions           |          Endangered" << endl;
    cout << "         Marine Iguana        |          Vulnerable" << endl;
    cout << "         Bluefin Tuna         |          Endangered" << endl;
    cout << "        Yellowfin Tuna        |     Critically Endangered" << endl;
    cout << "       Hawksbill Turtle       |     Critically Endangered" << endl;
    cout << "      Loggerhead Turtle       |          Vulnerable" << endl;
    cout << "      Leatherback Turtle      |          Vulnerable" << endl;
    cout << "         Green Turtle         |          Endangered" << endl;
    cout << "      Olive Ridley Turtle     |          Vulnerable" << endl;
    cout << "       Hector's Dolphin       |          Endangered" << endl;
    cout << "      Galápagos Penguin       |          Endangered" << endl;
    cout << "           Narwhal            |          Vulnerable" << endl;
    cout << "           Beluga             |          Vulnerable" << endl;
    cout << "=============================================================" << endl << endl;

    cout << " Would you like to go back to the menu? - Y/N" << endl << endl;
    cout << " Select >> ";

    returnToMenu();
}

void printTeamInformation()
{
    cout << "========================================================================================" << endl;
    cout << "                                    TEAM INFORMATION" << endl;
    cout << "========================================================================================" << endl << endl;
    cout << " Hello! Our team is TheFishers!" << endl;
    cout << " We are students from PGKPI. This is our program for the colaborative project AQUA." << endl << endl;
    cout << " Here are our names and tasks in this project:" << endl << endl;
    cout << "      Zjivko Spasov - 8G - HTML/CSS" << endl;
    cout << "      Soner Solakov - 8A - HTML/CSS" << endl;
    cout << "      Alexandra Staykova - 9V - JavaScript" << endl;
    cout << "      Tereza Opanska - 9V - C++" << endl;
    cout << "      Petar Petkov - 10G - SQL" << endl;
    cout << "      Stoyan Ponchev - 10G - SQL" << endl << endl;
    cout << " Thank you for using our program! We hope you like it!" << endl << endl;
    cout << "========================================================================================" << endl << endl;

    cout << " Would you like to go back to the menu? - Y/N" << endl << endl;
    cout << " Select >> ";

    returnToMenu();
}

void returnToMenu() 
{
    char answer;
    bool flag = false;

    while (flag == false)
    {
        cin >> answer;

        if (answer == 'Y' || answer == 'y') 
        {
            system("CLS"); 
            printMenu(); 
        }

        else if (answer == 'N' || answer == 'n')
        {
            exit(0);
        }

        else
        {
            cin.ignore(1000, '\n');
            cout << endl << "You entered an invalid operation. Please try again." << endl;
            cout << "Select >> ";
        }
    }
}