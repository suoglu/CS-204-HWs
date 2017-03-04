//  Yigit Suoglu 17720
// CS 204 ~ HW 2
// this header contains declerations of all functions  and #includes

#ifndef common_h
#define common_h


#endif /* common_h */

#include <iostream>
#include <string>
#include <fstream>
#include "node.h"

void clearList(node *racers);
void displayList(node *racers);
void readFromfile(node * & racers);
void readFromConsole(node * & racers);
void toUpper(string & str);
ifstream openFile();
void deleteElement(node *pre, node *current, node * & racers);
void addToList(int point, string driverName, node * & racers);
string writeSpace(string source, int outSize);
