// Yigit Suoglu ~ 17720
// cs 204 ~ hw3
// this file contains function declerations and #includes

#ifndef common_h
#define common_h


#include <iostream>
//#include <string> //included in StudentList.h
#include <fstream>

#include "StudentList.h"

using namespace std;

ifstream openFile();
void toLower(string & str);
void clearList(examNode * & exam);
int getInt();
int simpleStrToInt(string str);
bool isDigit(char ch);
bool isInt(string str);

#endif /* common_h */
