#pragma once

#include "menu.h"

using namespace std;

void OpenFile();

void CreateRecord();

void UpdateRecord(string search);

void DeleteRecord(string search);

void SearchRecord(string search);

void DisplayRecord();

void SaveToFile();

void MainProgram();

int inputChoiceProgramme();

bool idCheck(string id); 

bool idAlreadyExist(string id);