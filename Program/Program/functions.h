#pragma once

#include "menu.h"

using namespace std;

extern string user_status;

void openFile();

void createRecord();

void updateRecord(string search);

void deleteRecord(string search);

void searchRecord(string search);

void displayRecord();

void saveToFile();

void mainProgram();

int inputChoiceProgramme();

bool checkIdLenght(string id);

bool checkExistence(string id);