#include <iostream>
#include "Myclass.h"
using namespace std;    

int main (){
    cout << "Welcome to cgpa calculator" << endl;
    cout << "Enter the number of semesters: " << endl;
     int semesterNumber;
        cin >> semesterNumber;

    cout << "Enter the branch of student:"<<endl;

        int branchCode;
            cin >> branchCode;
    
        cout << "Enter the subject code: " << endl;
        int subjectCode;
            cin >> subjectCode;
    
        Semester s1;
        s1.setSemesterNumber(semesterNumber);
    
        Branch b1;
        b1.setBranchCode(branchCode);
    
        Subject sub1;
        sub1.setSubjectCode(subjectCode);


    cout << "Details of the student: " << endl;
    s1.displaySemesterNumber();
    b1.displayBranchCode();
    sub1.displaySubjectCode();
    return 0;
}