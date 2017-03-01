//Yigit Suoglu ~ 17720
//IMPORTANT NOTE: in this file first vector determines rows second vector colums
/*
 * Error codes:
 *  ~ '1': pixel value not in range
 *  ~ '2': file is not a matrix
 *  ~ anything else: file contains the char at error code itself, that char is not a digit
 */
#include "common.h"
#include <sstream>


void swp(int & x, int & y)
//swaps two integer
{
    int hold = x;
    x = y;
    y = hold;
}

void printMatrix(const vector<vector<int>> & matrix)
//this function prints matrix to the console
{
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << "\t"; //separate columns with tabs
        }
        cout << "\n"; //separate rows with endline
    }
}

void bubbleSort(vector<int> & list)
{
    bool change; //true if any elements swaped
    while(true)
    {
        change = false;
        for(int j = 0; (j < list.size() - 1); j++) //compare all adjacent
        {
            if(list[j] > list[j+1])
            {
                change = true;
                swp(list[j], list[j+1]);
            }
        }
        if(!change) //if no elemets are swaped at a pass list is sorted
        {
            return;
        }
    }
    
}

bool readMatrix(vector<vector<int>> & matrix, char & errorCode, int & pixel, unsigned long & rowDim)
//this function reads a matrix from a file, if file is not a matrix in range [0,255] it gives error and outof range value
{
    ifstream fin = openFile();

    
    
    rowDim = 0;//used to hold dimention of first row, which will be used as referance row
    unsigned long rowCount; //count each row, to be compared to referance row
    string inputRow, inputCol; //hold inputs to be processed
    while(getline(fin, inputRow)) //this loop reads and stores data into vector<vector<int>>
    {
        vector<int> hold; //construct row
        istringstream sin(inputRow);  //get each row as in an input stream
        rowCount = 0; //initilaze row counter
        while(sin >> inputCol)
        {
            rowCount++;
            pixel = strTOint(inputCol, errorCode); //convert pixel value to integer
            if((errorCode != '0')) //if data is not int or pixel value is not in range
            {
                return false;
            }
            else if(!isValidPixelVal(pixel, errorCode))
            {
                return false;
            }
            hold.push_back(pixel);
        }
        
        if(rowDim == 0)
        {
            rowDim = rowCount;
        }
        else if (rowCount != rowDim) //if dimension of this row is diffrent then referance row, meaning it is not matrix
        {
            errorCode = '2'; //save error code, code '2' is for non matrix file
            return false;
        }
        
        
        matrix.push_back(hold); //save constructed matrix
    }
    return true;
}

int medianFilterSingle(const vector<vector<int>> & src, const int & filterSize, unsigned long rowDim, unsigned long colmDim, int row, int colm)
//calculates median filter value of single matrix cell
{
    unsigned long rowB[2], colmB[2]; //used to determine boundries of filter
    {
        int diff = (filterSize - 1) / 2; //max differance (in x or y direction) between main pixel and other pixels at filter
        //four if-else statements below determines filter boundries
        if((row - diff) > 0) //#1
        {
            rowB[0] = row - diff;
        }
        else
        {
            rowB[0] = 0;
        }
        
        if((row + diff) < rowDim) //#2
        {
            rowB[1] = row + diff;
        }
        else
        {
            rowB[1] = rowDim - 1;
        }
        
        if((colm - diff) > 0) //#3
        {
            colmB[0] = colm - diff;
        }
        else
        {
            colmB[0] = 0;
        }
        
        if((colm + diff) < colmDim) //#4
        {
            colmB[1] = colm + diff;
        }
        else
        {
            colmB[1] = colmDim - 1;
        }
    }
    
    vector<int> filterElements;
    for (unsigned long i = rowB[0]; i <= rowB[1]; i++) //store pixels in filter
    {
        for (unsigned long j = colmB[0]; j <= colmB[1]; j++)
        {
            filterElements.push_back(src[i][j]);
        }
    }
    
    bubbleSort(filterElements);
    int filtered;
    
    if(isOdd(filterElements.size()))
    {
        filtered = filterElements[((filterElements.size() - 1)/2)];
    }
    else
    {
        filtered = (filterElements[filterElements.size()/2] + filterElements[(filterElements.size()/2) - 1])/2;
    }
    
    return filtered;
}

void medianFilter(const vector<vector<int>> & src, const int & filterSize, unsigned long rowDim, unsigned long colmDim, vector<vector<int>> & target)
//applies median filtering to a dimantions known matrix
{
    for(int i = 0; i < rowDim; i++)
    {
        vector<int> row;
        for (int j = 0; j < colmDim; j++)
        {
            row.push_back(medianFilterSingle(src, filterSize, rowDim, colmDim, i, j));
        }
        target.push_back(row);
    }
}
