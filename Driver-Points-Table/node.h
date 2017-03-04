//  Yigit Suoglu 17720
// CS 204 ~ HW 2
// this header contains structure for a link list node for racers

#ifndef node_h
#define node_h


#endif /* node_h */

using namespace std;

struct node
{
    string name;
    int point;
    node *next;
    
    //default constructor
    /*node::*/node ()
    :name(""), point(0), next(NULL)
    {}
    
    /*node::*/node (string s,int i) // node racer(s,i) seklinde olustur
    :name(s), point(i), next(NULL)
    {}
    
    //constructor
    /*node::*/node (string s,int i,node *n) // node racer(s,i,n) seklinde olustur
    :name(s), point(i), next(n)
    {}
};
