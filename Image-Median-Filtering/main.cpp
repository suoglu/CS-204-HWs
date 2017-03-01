//Yigit Suoglu ~ 17720
/*
 * Error codes:
 *  ~ '1': pixel value not in range
 *  ~ '2': file is not a matrix
 *  ~ anything else: file contains the char at error code itself, that char is not a digit
 */
#include "common.h"


int main()
{
    cout << "This program performs median filtering operation on an input matrix given in a text file\n";
    int filterSize = getFilterSize();
    unsigned long colmDim; //element count of row
    vector<vector<int>> matrix;
    { //store matrix
        int nonRangeInt; //to store pixel value that is not in range, if exists
        char errorCode = '0';
        if(!readMatrix(matrix, errorCode, nonRangeInt, colmDim)) //store matrix, if cannot give error
        {
            cout << "Error: ";
            if(errorCode == '1') //negative value
            {
                cout << "Pixel with value: " << nonRangeInt << " is not in range [0, 255]";
            }
            else if(errorCode == '2') //not matrix
            {
                cout << "Input file is not in matrix format";
            }
            else //not integer value
            {
                cout << "Input file contains invalid characters (e.g. " << errorCode << ")";
            }
            cout << "\nProgram Exiting...\n";

            return 1;
        }
    }
    unsigned long rowDim = matrix.size(); //element count of column
    cout << "\nINPUT MATRIX:\n\n";
    printMatrix(matrix);
    
    cout << "\nFILTERED MATRIX:\n\n";    
    vector<vector<int>> filteredMatrix;
    medianFilter(matrix, filterSize, rowDim, colmDim, filteredMatrix);
    printMatrix(filteredMatrix);
    return 0;
}
