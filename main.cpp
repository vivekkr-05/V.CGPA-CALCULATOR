#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "Myclass.h"

using namespace std;

vector<Branch> initializeData()
{
    vector<Branch> allBranches;

    Branch cse;
    cse.branchName = "Computer Science (CSE)";
    Semester s1_cse, s2_cse;
    s1_cse.semesterNumber = 1;
    s1_cse.subjects = {Subject("Maths-I"), Subject("C-Prog"), Subject("Physics"), Subject("English"), Subject("Workshop")};
    s2_cse.semesterNumber = 2;
    s2_cse.subjects = {Subject("Data Structures"), Subject("Discrete Math"), Subject("Digital Logic"), Subject("Python"), Subject("Environment")};
    cse.semesters = {s1_cse, s2_cse};

    Branch ee;
    ee.branchName = "Electrical Engineering (EE)";
    Semester s1_ee, s2_ee;
    s1_ee.semesterNumber = 1;
    s1_ee.subjects = {Subject("Basic Electrical"), Subject("Maths-I"), Subject("Physics"), Subject("Graphics"), Subject("English")};
    s2_ee.semesterNumber = 2;
    s2_ee.subjects = {Subject("Circuits"), Subject("Maths-II"), Subject("Machines"), Subject("EMF"), Subject("C++")};
    ee.semesters = {s1_ee, s2_ee};

    Branch ece;
    ece.branchName = "Electronics Engineering (ECE)";
    Semester s1_ece, s2_ece;
    s1_ece.semesterNumber = 1;
    s1_ece.subjects = {Subject("Network Theory"), Subject("Maths-I"), Subject("Physics"), Subject("Semi-conductors"), Subject("English")};
    s2_ece.semesterNumber = 2;
    s2_ece.subjects = {Subject("Signals"), Subject("Maths-II"), Subject("Analog Electronics"), Subject("Digital Electronics"), Subject("C++")};
    ece.semesters = {s1_ece, s2_ece};

    allBranches.push_back(cse);
    allBranches.push_back(ee);
    allBranches.push_back(ece);
    return allBranches;
}

int main()
{
    vector<Branch> universityData = initializeData();
    string studentName;
    int bIdx, sNum;

    cout << "===== UNIVERSITY CGPA CALCULATOR =====" << endl;
    cout << "Enter Student Name: ";
    getline(cin, studentName);

    cout << "\nSelect Branch:\n0: CSE\n1: EE\n2: ECE\nChoice: ";
    cin >> bIdx;

    if (bIdx < 0 || bIdx > 2)
    {
        cout << "Invalid Branch Selection." << endl;
        return 1;
    }

    cout << "Select Semester (1 or 2): ";
    cin >> sNum;
    int sIdx = sNum - 1;

    Semester &currentSem = universityData[bIdx].semesters[sIdx];

    cout << "\n--- Enter Marks for " << currentSem.subjects.size() << " Subjects ---\n";
    for (auto &sub : currentSem.subjects)
    {
        cout << "\nSubject: " << sub.name << endl;
        cout << "  Theory (Max 70): ";
        cin >> sub.theoryMarks;
        cout << "  Practical (Max 30): ";
        cin >> sub.practicalMarks;
    }

    cout << "\n\n========================================" << endl;
    cout << "             REPORT CARD                " << endl;
    cout << "========================================" << endl;
    cout << "Name:   " << studentName << endl;
    cout << "Branch: " << universityData[bIdx].branchName << endl;
    cout << "Sem:    " << sNum << endl;
    cout << "----------------------------------------" << endl;
    cout << left << setw(20) << "Subject" << setw(10) << "Total" << setw(10) << "Grade" << endl;
    cout << "----------------------------------------" << endl;

    for (auto &sub : currentSem.subjects)
    {
        cout << left << setw(20) << sub.name
             << setw(10) << sub.getTotalMarks()
             << setw(10) << sub.getLetterGrade() << endl;
    }

    cout << "----------------------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "Semester Percentage: " << currentSem.calculatePercentage() << "%" << endl;
    cout << "Semester GPA:        " << currentSem.calculateGPA() << endl;
    cout << "========================================" << endl;

    return 0;
}