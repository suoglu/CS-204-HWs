//  Yigit Suoglu 17720
// CS 204 ~ HW 2
// file contains some basic functions


#include "common.h"

using namespace std;

void toUpper(string & str)
//coverts string to uppercase
{
    for(int j = 0; j < str.size(); j++)
    {
        if(str[j] <= 'z' & 'a' <= str[j]) //if string is lowercase
        {
            str[j] = str[j] + ('B' - 'b'); //convert to uppercase
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

string writeSpace(string source, int outSize)
//writes spaces after source string untill out size matched, for better spaces between tables
{
    if(outSize <= source.size()) //if source is bigger that size
    {
        return source; //return source
    }
    string result = source;
    for(int i = source.size(); i < outSize; i++) //add " " for each differnce
    {
        result = result + " ";
    }
    return result;
}

