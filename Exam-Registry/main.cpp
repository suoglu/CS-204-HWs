// Yigit Suoglu ~ 17720
// cs 204 ~ hw3
// this file contains main function

#include "common.h"

using namespace std;

int main()
{
    int op;
    StudentList list;
    string buffer1, buffer2;
    do {
        cout << "Exam Grades\n";
        cout << "-----------------------------------\n";
        cout << "Please select one option [1..7]:\n";
        cout << "1. Load information from a file\n";
        cout << "2. Add student and exam manually\n";
        cout << "3. Delete a student\n";
        cout << "4. Display exam grades of a student\n";
        cout << "5. Display exam grades of all students in alphabetical order\n";
        cout << "6. Display exam grades of all students in reverse alphabetical order\n";
        cout << "7. Exit\n";
        cout << "Your choice: ";
        op = getInt();
        switch (op) {
            case 1:
                list.addFromFile();
                break;
            case 2:
                cout << "Please enter the user name of the student: ";
                cin >> buffer1;
                cout << "Please enter the name of the course: ";
                cin >> buffer2;
                do {
                    cout << "Please enter the grade[0..100]: ";
                    op = getInt();
                } while ((op > 100) | (op < 0));
                list.addExam(buffer1, buffer2, op);
                op = 5;
                break;
            case 3:
                cout << "Please enter the user name of the student: ";
                cin >> buffer1;
                list.deleteStudent(buffer1);
                break;
            case 4:
                cout << "Please enter the user name of the student: ";
                cin >>  buffer2;
                list.printStudent(buffer2);
                break;
            case 7:
                list.deleteAll();
                
                return 0;
            case 5:
                list.printAllAZ();
                break;
            case 6:
                list.printAllZA();
                break;
            default:
                cout << "\nUnknown operation!\n";
                break;
        }
        cout << endl;
        
    } while (op != 7);
    
    return -1;
}
