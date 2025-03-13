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

#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 20, SECTIONS = 2, GRADE = 12, GRADES = 5;
const string FILENAME = "students.txt";
const string NEXT_SECTION = "*****";

struct Student
{
   string mId;
   string mName;
   float mLab;
   float mPa;
   float mQuiz;
   float mMidterm;
   float mFinal;
   float mAverage;
   string mGrade;
};

void assignGrade(Student data[][SECTIONS], const int size[SECTIONS]);
void computeAverage(Student data[][SECTIONS], const int size[SECTIONS]);
void computeAverage(const Student data[][SECTIONS], const int size[SECTIONS], double averages[SECTIONS]);
void counteGrade(const Student data[][SECTIONS], const int size[SECTIONS], int grade[GRADE][SECTIONS]);
void displayData(const Student data[][SECTIONS], const int size[SECTIONS]);
void displayStat(const Student data[][SECTIONS], const int size[SECTIONS], const double averages[SECTIONS], const int grade[GRADE][SECTIONS]);
void loadData(Student data[][SECTIONS], int size[SECTIONS]);
void sortData(Student data[][SECTIONS], const int size[SECTIONS]);


#endif