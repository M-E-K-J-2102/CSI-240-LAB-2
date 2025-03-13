/*
Author:           Matthew Kane
Class:            CSI-240-04
Assignment:       Lab 2
Date Assigned:    2/2/2024
Due Date:         6/2/2024 @ 1:00 PM

Description:
A program that can help teachers with grading

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff;
and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may
then retain a copy of this assignment on its database for the purpose of future
plagiarism checking)
-----------------------------------------------------------------------------------------
Sources:
*/

#include "header.h"
#include "functions.cpp"

int main()
{
    Student data[SECTIONS][MAX];
    int size[SECTIONS];
    double averages[SECTIONS];
    int letterGrade[GRADE][SECTIONS];

    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(1);
    loadData(data, size);
    computeAverage(data, size);
    assignGrade(data, size);
    sortData(data, size);
    displayData(data, size);
    computeAverage(data, size, averages);
    counteGrade(data, size, letterGrade);
    displayStat(data, size, averages, letterGrade);
    return 0;
}