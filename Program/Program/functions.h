#pragma once

#include "menu.h"

using namespace std;

void openFile();

void createRecord();

void updateRecord(string search);

void deleteRecord(string search);

void searchRecord(string search);

void displayRecord();

void saveToFile();

void mainProgram();

int inputChoiceProgramme();

bool idCheck(string id); 

bool idAlreadyExist(string id);