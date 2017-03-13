//  Yigit Suoglu 17720
// CS 204 ~ HW 2
// this file contains main program

#include "common.h"

using namespace std;




int main()
{
    short op;
    node *racers = NULL;
    cout << "Welcome!";
    do
    {
        cout << "\n\nFormula 1 Points Table System\n";
        cout << "-----------------------------------\n";
        cout << "Please select one option [1..4]:\n";
        cout << "1. Load driver names and points from a file\n";
        cout << "2. Insert a new driver / Modify points of an existing driver\n";
        cout << "3. Display points table in alphabetical order\n";
        cout << "4. Exit\n";
        cout << ">> ";
        cin >> op;
        switch (op)
        {
            case 1:
                readFromfile(racers);
                break;
            case 2:
                readFromConsole(racers);
                break;
            case 3:
                displayList(racers);
                break;
            case 4:
                clearList(racers);
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "!!!!!!!!!!!!!FATAL ERROR!!!!!!!!!!!!!\n";
                cout << "Unknown option!\n";
                cin.clear();//Bug fix: program chash non integer operation code
                cin.ignore();
                //return 1;
                break;
        }
        
    }while(true);
    
    return 1;
}
