//Yigit Suoglu ~ 17720
//Used as a common header file for all cpp files

#ifndef common_h
#define common_h

#endif /* common_h */

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream openFile(); //this function opens file

void bubbleSort(vector<int> & list); //sorts input matrix

bool isDigit(char ch, char & code); //checks if input char is a digit

bool isPosInteger(string str, char & code); //checks input string is a positive int

int strTOpint(string str, char & code); //converts positive integer string to int

int strTOint(string str, char & code); //converts integer string to int

bool isOdd(unsigned long num); //checks if input is an odd number

void swp(int & x, int & y); //swaps two integer

int getFilterSize(); //gets filter size from user

bool isValidPixelVal(int pix, char & errorCode); //checks if input int is in pixel range {[0:255]

bool readMatrix(vector<vector<int>> & matrix, char & errorCode, int & pixel, unsigned long & rowDim); //stores matrix data from a file

void printMatrix(const vector<vector<int>> & matrix); //prints matrix

void medianFilter(const vector<vector<int>> & src, const int & filterSize, unsigned long rowDim, unsigned long colmDim, vector<vector<int>> & target); //applies median filter to a matrix

int medianFilterSingle(const vector<vector<int>> & src, const int & filterSize, unsigned long rowDim, unsigned long colmDim, int row, int colm); //apply median filter to single cell
