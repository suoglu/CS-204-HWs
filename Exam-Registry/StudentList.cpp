// Yigit Suoglu ~ 17720
// cs 204 ~ hw3
// this file contains student list class

//#include "StudentList.h"
#include "common.h"


using namespace std;

StudentList::StudentList() //default constructor
{
    head = NULL;
    tail = NULL;
}

void StudentList::addExam(string userName, string courseName, int grade)
{
    studentNode * student = this->addFindStudent(userName); //get pointer for student
    
    if(student->headExamList != NULL) //if exam list exists
    {
        examNode * lastExam = student->headExamList; //get pointer for exam list of student
    
        while (lastExam->next != NULL) //carry pointer to point last entered exam
        {
            lastExam = lastExam->next;
        }
        lastExam->next = new examNode(courseName, grade); //add new grade to after last exam
    }
    else //if exam list does not exists
    {
        student->headExamList = new examNode(courseName, grade); //create list
    }
    cout << "Exam for " << courseName << " with grade " << grade << " is added for " << student->userName << endl;
}

void StudentList::deleteStudent(string userName)
{
    studentNode * toBedeleted = this->findStudent(userName);
    if (toBedeleted == NULL)
    {
        cout << "Student does not exist in the list.\n\n";
        return;
    }
    
    //remove connections
    if(toBedeleted == this->head)
    {
        if(toBedeleted == this->tail) //if it is only node of list
        {
            this->head = this->tail = NULL;
        }
        else
        {
            toBedeleted->next->prev = NULL;//toBedeleted->prev;
            this->head = toBedeleted->next;
        }
    }
    else if(toBedeleted == this->tail)
    {
        this->tail = toBedeleted->prev;
        toBedeleted->prev->next = NULL;//toBedeleted->next;
    }
    else
    {
        toBedeleted->next->prev = toBedeleted->prev;
        toBedeleted->prev->next = toBedeleted->next;
    }
        
    
    clearList(toBedeleted->headExamList); // clear exam list
    
    delete toBedeleted; //delete pointer
    cout << "\nStudent " << userName << " has been deleted.\n\n";
}

void StudentList::printAddrs(studentNode * node) //prints student at given pointer
{
    cout << endl << node->userName << endl; //print user name of adressed student
    cout << "------------------------------\n";
    examNode * exam = node->headExamList; //set head exam to pointer
    while(exam != NULL) // while pointer point some exam
    {
		int fix = 1; //get the digit count of grade
		if(exam->grade == 100)
		{
			fix = 3;
		}
		else if(exam->grade > 9)
		{
			fix = 2;
		}
		string space = ":";//start space between course name and grade
		for(int i = exam->courseName.size(); i < ( 29 - fix); i++) //fill rest with spaces
		{
			space = space + " ";
		}

        cout << exam->courseName << space << exam->grade << endl; //print pointed exam
        exam = exam->next; // set pointer to next exam
    }
    
}

void StudentList::printStudent(string userName)
{
    studentNode * toBePrinted = this->findStudent(userName); //find adress of student
    if(toBePrinted == NULL)
    {
        cout << "Student does not exist in the list.\n\n";
        return;
    }
    this->printAddrs(toBePrinted); //print student at found adress
    
}

void StudentList::printAllAZ() //alphabetical order display
{
    if(this->head == NULL)
    {
        cout << "Student list is empty.\n";
        return;
    }
    cout << "Printing all students in alphabetical order.\n";
    studentNode * print = this->head; //set head to be printed
    while(print != NULL) //while pointer points to an adress of a student
    {
        this->printAddrs(print); //print student at that adress
        print = print->next; //set next to be printed
    }
}

void StudentList::printAllZA() //reverse alphabetical order display
{
    if(this->tail == NULL)
    {
        cout << "Student list is empty.\n";
        return;
    }
    cout << "Printing all students in reverse alphabetical order.\n";
    studentNode * print = this->tail; //set tail to be printed
    while(print != NULL) //while pointer points to an adress of a student
    {
        this->printAddrs(print); //print student at that adress
        print = print->prev; //set previous to be printed
    }
}

studentNode * StudentList::findStudent(string userName)  //returns pointer of given student, return NULL if cannot find
{
    toLower(userName); //usernames stored as lowercase
    studentNode * inspect = this->head; //start search from head
    while (inspect != NULL) //while inspect is pointing an element
    {
        if(inspect->userName == userName) //if elements username is same as we search
        {
            return inspect; //return pointer
        }
        inspect = inspect->next; //if not inspect next one
    }
    return NULL; //if cannot find return NULL
}

studentNode * StudentList::addFindStudent(string userName)
//returns a pointer to the student whose user name given as an input.
//If such student does not exists creates it and returns pointer
{
    toLower(userName);
    studentNode * student = this->findStudent(userName); //search given
    if(student != NULL) //check if student exist return adress
    {
        return student;
    }
    
    student = new studentNode(userName); //create node
    
    //code below here places new node to list
   //------------------------------------------
    if (this->head == NULL) //check if list is empty
    { //Note: if head is NULL, tail is also NULL thus list is empty
        this->head = this->tail  = student; //set both tail and head to new node, since list is only one node
        cout << "A new student with user name " << student->userName << " has been added.\n";
        return student;
    }
    
    studentNode * inspecting = this->head;//start looking from head
    if(inspecting->userName > student->userName)
    {
        this->addStudentAfter(NULL, student);
        return student;
    }
    while(inspecting->next != NULL)//while the node after inspected exists
    {
        if ((student->userName > inspecting->userName) & (student->userName < inspecting->next->userName)) //if student is between inspecting and next
        {
            this->addStudentAfter(inspecting, student); //add it after inspecting
            return student;
        }
        inspecting = inspecting->next;//inspect next
    }
    this->addStudentAfter(inspecting, student);//add element as tail if cannot put bewteen nodes
    return student;
}

void StudentList::addStudentAfter(studentNode * nodeInTheList, studentNode * toBeAdded) //adds student "toBeAdded" after student "nodeInTheList"
{ //if nodeInTheList is NULL add element to head
    if(nodeInTheList == NULL) //add as head
    {
        //connect toBeAdded to others
        toBeAdded->prev = NULL;
        toBeAdded->next = this->head;
        
        //connect others to toBeAdded
        toBeAdded->next->prev = toBeAdded;
        this->head = toBeAdded;
    }
    else if(nodeInTheList->next == NULL) //add as tail
    {
        //connect toBeAdded to others
        toBeAdded->prev = nodeInTheList;
        toBeAdded->next = NULL;
        
        //connect others to toBeAdded
        this->tail = toBeAdded;
        toBeAdded->prev->next = toBeAdded;
    }
    else
    {
        //connect toBeAdded to others
        toBeAdded->prev = nodeInTheList;
        toBeAdded->next = nodeInTheList->next;
        
        //connect others to toBeAdded
        toBeAdded->next->prev = toBeAdded;
        toBeAdded->prev->next = toBeAdded;
    }
    cout << "A new student with user name " << toBeAdded->userName << " has been added.\n";
}

void StudentList::deleteAll()
{
    this->deleteAdr(this->head); //delete starting head
    this->head = this->tail = NULL; //set head and tail to NULL
}

void StudentList::deleteAdr(studentNode * dlt)
{
    if(dlt == NULL)
    {
        return; //bug fix: if list node does not exists return
    }
    clearList(dlt->headExamList); //clear exam list
    if(dlt->next != NULL) //if next node exists
    {
        this->deleteAdr(dlt->next); //delete next node first
    }
    delete dlt; //later delete this node
}


void StudentList::addFromFile() //add data from file
{ //Warning: does not make input check, file must be in correct form
    ifstream fin = openFile();
    
    string userName, course;
    int grade;
    while(fin >> userName)
    {
        fin >> course;
        fin >> grade;
        this->addExam(userName, course, grade);
    }
    cout << "File has been processed.\n";
}























