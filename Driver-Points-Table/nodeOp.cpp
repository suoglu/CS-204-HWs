//  Yigit Suoglu 17720
// CS 204 ~ HW 2
// file contains node operations

#include "common.h"
#define nonPosError " has not been added since the initial points cannot be non-positive.\n"
#define createFeedBack " has been added to list with initial points: "
#define updateFeedBack "  has been updated and new point is "
#define deleteDeefBack " has been removed from the list since his points became non-positive.\n"

using namespace std;

void clearList(node * racers)
//clears list recursively
{
    if(racers == NULL) //bug fix: if node if NULL return
        return;
    
    if(racers->next != NULL) //if not last element
    {
        clearList(racers->next); //apply same procedure for next elements
    }
    delete racers; //delete this pointer
}
/*
void clearList(node * racers)
    //delete all racer nodes
{
    node *toBeDeleted;
    while(racers != NULL) //while pointer points to a racer
    {
        racers = racers->next; //store next racer
        toBeDeleted = racers; //set racer to be deleted
        delete toBeDeleted; //delete current racer
    }
}*/

void displayList(node * racers)
    //display list
{
    if(racers == NULL)
    {
        cout << "The points table is empty\n\n";
        return;
    }
    cout << "\nPoints Table\n--------------------------------------\n";
    while(racers!=NULL) //while pointer points to a racer
    {
        string display = writeSpace(racers->name, 28);
        cout << display << "\t\t" << racers->point << endl; //display
        racers=racers->next; //set pointer to the next one
    }
}

void readFromfile(node * & racers)
//read driver information from file and add it to linked list
{
    ifstream fin = openFile();
    string driverName;
    int point;
    while(fin >> driverName)
    {
        fin >> point;
        addToList(point, driverName, racers);
    }
}

void readFromConsole(node * & racers)
//read driver information from console input and add it to linked list
{
    string driverName;
    int point;
    cout << "Please enter name of the driver you wish to add/modify: ";
    cin >> driverName;
    cout << "Please enter how many points you wish to initialize/add/remove: ";
    cin >> point;
    addToList(point, driverName, racers);
}

void addToList(int point, string driverName, node * & racers)
{
    toUpper(driverName); //convert all to uppercase
    node *pre = NULL;
    node *crnt = racers;
    bool createNew = point > 0; //should we create new driver if not exist?
    
    if(crnt == NULL) //if list is empty modify head pointer
    {
        if (createNew)
        {
            racers = new node(driverName,point);
            cout << driverName << createFeedBack << point << endl;
        } else {
            cout << driverName << nonPosError;

        }
        return;
    }
    while(crnt != NULL) //while current element is a node
    {
        
        if(crnt->name == driverName) //if same driver
        {
            int newPoint = point + crnt->point;
            if(newPoint > 0) //if total point positive
            {
                crnt->point = newPoint; //update
                cout << driverName << updateFeedBack << newPoint << endl;
            }
            else //if total point non-positive
            {
                deleteElement(pre, crnt, racers); //delete
                cout << driverName << deleteDeefBack;
            }
            return;
        }
        else if((crnt->name) > driverName) //if driver is between pre and current
        {
            if(pre == NULL)
            {
                if(createNew) //if we create new
                {
                    racers = new node(driverName, point, crnt);
                    cout << driverName << createFeedBack << point << endl;
                }
                else
                {
                    cout << driverName << nonPosError;
                }
                return;
            }
            if((pre->name) < driverName)
            {
                if(createNew) //if we create new
                {
                    pre->next = new node(driverName, point, pre->next); //create between
                    cout << driverName << createFeedBack << point << endl;
                }
                else
                {
                    cout << driverName << nonPosError;
                }
                return;
            }
        }
        pre = crnt; //update previous to current for next cycle
        crnt = crnt->next; //update current to next for next cycle
    }
    
    if(createNew) //add to end of list
    {
        pre->next = new node(driverName,point);
        cout << driverName << createFeedBack << point << endl;
    }
    else
    {
        cout << driverName << nonPosError;
    }
    
}

void deleteElement(node * pre, node * current, node * & racers)
//deletes current node and connects previous to next
{
    if (pre == NULL) // if we delete first node of list
    {
        racers = current->next; //change head
    }
    else //if we delete middle or end node of node
    {   //note last node's next points NULL thus bottom statement wont cause problem
        pre->next = current->next; //connect its next to previous's next
    }
    delete current;
    
}



