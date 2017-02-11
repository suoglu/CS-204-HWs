//Yigit Suoglu ~ 17720
//contains functions for getting inputs and input checks

#include "common.h"


bool isOdd(unsigned long num)
//chechs for given int is odd or not
{
    return ((num % 2) == 1);
}


int getFilterSize()
//gets a filter size, checks if it is valid, if not ask again
{
    int filterSize;
    bool cond = true; //normally loop works indefintly
    do
    {
        char dummy;
        string input;
        cout << "Enter the filter size (must be a positive odd integer): ";
        cin >> input;
        filterSize = strTOpint(input, dummy); //convert it to intger, if entered value is not
                                     // positive integer returns -1
        if(!isOdd(filterSize) | (filterSize == -1)) //check for error code and oddness
        {
            cout << "Error. ";
            continue; //if not odd or positive int contunue iteration
        }
        cond = false; //if input is valid get out of loop
        
    }while(cond);
    
    return filterSize;
}

bool isValidPixelVal(int pix, char & errorCode)
//checks if pixel value is an positive integer less than 256
//if input is integer but not in valid ranfe
{
    
    if((pix >= 0)&(pix <= 255))  //but negative or higer than 255
    {
        return true;
    }
    errorCode = '1'; //edit error code
    return false;
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
