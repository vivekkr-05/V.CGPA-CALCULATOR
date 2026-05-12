#ifndef MYCLASS_H
#define MYCLASS_H
#include <iostream>
using namespace std;

class Semester {
    private:
        int semeesterNumber;
    public:
        void setSemesterNumber(int value) {
            semeesterNumber = value;
        }

        void displaySemesterNumber() {
            cout << "Semester Number: " << semeesterNumber << endl;
        }



};

class Subject {
    private:
        int subjectCode;
    public:
        void setSubjectCode(int value) {
            subjectCode = value;
        }

        void displaySubjectCode() {
            cout << "Subject Code: " << subjectCode << endl;
        }
};

class Branch{
    private:
        int branchCode;
    public:
        void setBranchCode(int value) {
            branchCode = value;
        }
        void displayBranchCode() {
            cout << "Branch Code: " << branchCode << endl;
        }
};


#endif