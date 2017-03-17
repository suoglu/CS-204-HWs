//  Yigit Suoglu 17720
// CS 204 ~ HW 3
// file contains some basic functions


#include "common.h"

using namespace std;

void toLower(string & str)
//coverts string to lowercase
{
    for(int j = 0; j < str.size(); j++)
    {
        if(str[j] <= 'Z' & 'A' <= str[j]) //if string is lowercase
        {
            str[j] = str[j] + ('b' - 'B'); //convert to uppercase
        }
    }
}

ifstream openFile() //this function opens file
{
    ifstream fin;
    do //this loop opens file
    {
        string fileName;
        cout << "\nEnter the name of the file: ";
        cin >> fileName;
        fin.open(fileName);
        if(!fin.fail()) //if file opened succesfully...
        {
            break; //...break the loop
        }
        //if file cannot opened give error massege
        cout << "\nError: Could not open the file " << fileName << endl;
        fin.clear();
    }while(true); //loop continues untill it is broken by if statement
    return fin;
}

void clearList(examNode * & exam)
//clears exam list recursively
{
    if(exam == NULL) //bug fix: if node does not exists return
    {
        return;
    }
    
    if(exam->next != NULL) //if not last element
    {
        clearList(exam->next); //apply same procedure for next elements
    }
    
    delete exam; //delete this pointer
    exam = NULL; //set pointer NULL
}

int getInt() //get integer from input, does input check, asks user until it gets a positive integer
{
    string in;
    cin >> in; //get input as a string
    while (!isInt(in)) //while string is not an integer
    {
        cout << in << " is not an integer value!\nPlease enter integer: "; //give error
        cin >> in; //ask & get again
    }
    
    return simpleStrToInt(in); //convert string to int and return
}

//IMPORTANT_NOTE:functions below are designed to work with positive integers

bool isDigit(char ch)
//Takes a char input than compares it with the boundries of digit chars (e.g. '6')
{
    
    return (((ch >= '0') & (ch <= '9')) | (ch == '\0'));
    //return (((int)ch >= 48) & ((int)ch < 58)); //if not in range of digits return true
}

bool isInt(string str) // return true if input is integer
{
    for(int j = 0; j <= str.size(); j++)
    {
        
        if(!isDigit(str[j]))
        { return false; }
    }
    return true;
}

int simpleStrToInt(string str) //convert string to int. Note: input must be at unsigned integer format
{
    int target = 0; //to be returned
    for(int j = 0; j < str.length(); j++)
    {
        if(str[j] == '\0')
        {
            continue;
        }
        target *= 10; //go to next power
        int addition = ((int)str[j] - 48); //converts digit char to int
        target += addition; //add Converted value
    }
    
    return target;
}

