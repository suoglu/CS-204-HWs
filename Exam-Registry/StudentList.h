// Yigit Suoglu ~ 17720
// cs 204 ~ hw3
// this header contains student list class and structures

#ifndef examRegistryStructs_h
#define examRegistryStructs_h

//#include "common.h"
#include <string>

using namespace std;

struct examNode
{
    string courseName;
    int grade;
    examNode * next;
    
    /*examNode::*/examNode ()
    :courseName(""), grade(-1), next(NULL)
    {}
    
    /*examNode::*/examNode (string courseName,int grade)
    :courseName(courseName), grade(grade), next(NULL)
    {}
    
    /*examNode::*/examNode (string courseName,int grade,examNode *n)
    :courseName(courseName), grade(grade), next(n)
    {}
};

struct studentNode
{
    string userName;
    examNode * headExamList;
    studentNode * next;
    studentNode * prev;

    /*studentNode::*/studentNode ()
    :userName(""), headExamList(NULL), next(NULL), prev(NULL)
    {}
    /*studentNode::*/studentNode (string uName)
    :userName(uName), headExamList(NULL), next(NULL), prev(NULL)
    {}
    /*studentNode::*/studentNode (string uName, studentNode * prev, studentNode * next)
    :userName(uName), headExamList(NULL), next(next), prev(prev)
    {}
    /*studentNode::*/studentNode (string uName, studentNode * prev, studentNode * next, examNode * exHead)
    :userName(uName), headExamList(exHead), next(next), prev(prev)
    {}
    
};

class StudentList
{
public:
    StudentList();
    void addFromFile();
    void addExam(string userName, string courseName, int grade);
    void deleteStudent(string userName);
    void printStudent(string userName);
    studentNode * findStudent(string userName);
    void printAddrs(studentNode * node);
    void printAllAZ(); //alphabetical order display
    void printAllZA(); //reverse alphabetical order display
    studentNode * addFindStudent(string userName);
    void addStudentAfter(studentNode * nodeInTheList, studentNode * toBeAdded); //adds student "toBeAdded" after student "nodeInTheList"
    void deleteAll(); //to deallocate all dynamic data
    void deleteAdr(studentNode * dlt); //deallocate after input data recursively
private:
    studentNode * head;
    studentNode * tail;
    
};

#endif /* examRegistryStructs_h */
