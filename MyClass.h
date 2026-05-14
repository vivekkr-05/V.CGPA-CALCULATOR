#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Subject
{
public:
    string name;
    int theoryMarks;
    int practicalMarks;
    int credits;

    Subject(string n, int c = 4) : name(n), theoryMarks(0), practicalMarks(0), credits(c) {}

    int getTotalMarks()
    {
        return theoryMarks + practicalMarks;
    }

    float getGradePoint()
    {
        int total = getTotalMarks();
        if (total >= 90)
            return 10.0;
        if (total >= 80)
            return 9.0;
        if (total >= 70)
            return 8.0;
        if (total >= 60)
            return 7.0;
        if (total >= 50)
            return 6.0;
        if (total >= 40)
            return 5.0;
        return 0.0;
    }

    string getLetterGrade()
    {
        float gp = getGradePoint();
        if (gp == 10.0)
            return "O";
        if (gp == 9.0)
            return "A+";
        if (gp == 8.0)
            return "A";
        if (gp == 7.0)
            return "B+";
        if (gp == 6.0)
            return "B";
        if (gp == 5.0)
            return "C";
        return "F";
    }
};

class Semester
{
public:
    int semesterNumber;
    vector<Subject> subjects;

    float calculateGPA()
    {
        float totalPoints = 0;
        int totalCredits = 0;
        for (auto &s : subjects)
        {
            totalPoints += (s.getGradePoint() * s.credits);
            totalCredits += s.credits;
        }
        return (totalCredits == 0) ? 0 : totalPoints / totalCredits;
    }

    float calculatePercentage()
    {
        float obtained = 0;
        for (auto &s : subjects)
        {
            obtained += s.getTotalMarks();
        }
        return (obtained / (subjects.size() * 100.0)) * 100.0;
    }
};

class Branch
{
public:
    string branchName;
    vector<Semester> semesters;
};

#endif