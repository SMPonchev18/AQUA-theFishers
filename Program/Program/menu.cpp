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

int inputChoice()   // Takes the user's choice
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

void choice(int user_choice)    // Takes the user to the different operations depending on their choice
{
    system("CLS");

    switch (user_choice)
    {
    case 1:
        mainProgram();
        break;

    case 2:
        printSpecies();
        break;

    case 3:
        printUsage();
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

void printSpecies()
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

void printUsage()
{
    cout << "============================================================================" << endl;
    cout << "                                 HOW TO USE                                 " << endl;
    cout << "============================================================================" << endl;
    cout << " By choosing 1 on the main menu, you're taken to a second menu where you can" << endl;
    cout << "see the different things you can do with records." << endl;
    cout << " By creating records, you can keep track of the marine wildlife and make sure" << endl; 
    cout << "species aren't going extinct." << endl << endl;
    cout << "    Choosing option 1 you are allowed to create a new record, by inputing an ID" << endl; 
    cout << "   for it and entering the name of the animal that the record is for." << endl;
    cout << "    Choosing option 2 you are allowed to update an already existing record in" << endl;
    cout << "   case you made a mistake when creating it or it's information changed." << endl;
    cout << "    Choosing option 3 you can delete an existing record." << endl;
    cout << "    Choosing option 4 you can search for a particular record by inputing it's ID." << endl;
    cout << "    Choosing option 5 you can see all of the records created displayed in a list." << endl;
    cout << "    Choosing option 6 you return to the main menu. Choosing option 6 is very" << endl; 
    cout << "   important because it also saves any changes that you have made to the records." << endl;
    cout << "   If you exit the program without choosing option 6, you will lose your changes!" << endl << endl;

    cout << " By choosing 2 on the main menu you get taken to a list of endangered animals." << endl;
    cout << "This option is mainly for edicational purposes and cannot be edited by the user." << endl;

    cout << " By choosing 3 you get taken to the information you are reading now." << endl;

    cout << " By choosing 4 you get taken to the information about our team." << endl;

    cout << " By choosing 5 you can exit the program." << endl;
    cout << "============================================================================" << endl << endl;

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
    cout << "      Zhivko Spasov - 8G - HTML/CSS" << endl;
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

        if (answer == 'Y' || answer == 'y') // User wants to return to the menu
        {
            system("CLS"); 
            printMenu(); 
        }

        else if (answer == 'N' || answer == 'n')    // User wants to exit the program
        {
            exit(0);
        }

        else    // Incorrect input
        {
            cin.ignore(1000, '\n');
            cout << endl << "You entered an invalid operation. Please try again." << endl;
            cout << "Select >> ";
        }
    }
}