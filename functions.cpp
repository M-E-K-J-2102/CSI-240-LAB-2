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
-https://stackoverflow.com/questions/993324/how-to-check-if-a-pointer-is-valid
-https://stackoverflow.com/questions/21991369/bubble-sort-c
*/
#include "header.h"

/* Function:   assignGrade (Student, const int)
*   Purpose:   Gives a student their letter grade
*       Pre:   Student must be initialized, populated and their average must have already been calculated
*      Post:   data[][].mGrade is given a char value
****************************************************************/
void assignGrade (Student data[][MAX], const int size[SECTIONS])
{
    float avg;
    string grade;

    for (int i = 0; i < SECTIONS; i++)
    {

        for (int j = 0; j < MAX; j++)
        {
            // Calculate the letter grade (A, B, C, D, F)
            if(static_cast<int>(data[i][j].mAverage) >= 90)
            {
                grade = "A";

                // Makes sure not to give out an A+
                if(static_cast<int>(data[i][j].mAverage) % 10 >= 7)
                {
                    break;
                }
            }
            else if (static_cast<int>(data[i][j].mAverage) >= 80)
            {
                grade = "B";
            }
            else if (static_cast<int>(data[i][j].mAverage) >= 70)
            {
                grade = "C";
            }
            else if (static_cast<int>(data[i][j].mAverage) >= 60)
            {
                grade = "D";
            }
            else
            {
                grade = "F";
            }

            // Calculate if grade needs a +, - or normal letter
            if (static_cast<int>(data[i][j].mAverage) % 10 >= 7 && grade != "F")
            {
                grade += "+";
            }
            else if(static_cast<int>(data[i][j].mAverage) % 10 < 3 && grade != "F")
            {
                grade += "-";
            }

            data[i][j].mGrade = grade;
        }
    }
}

/* Function:   computeAverage (Student, const int)
*   Purpose:   calculates a student's average
*       Pre:   Student must be initialized and populated
*      Post:   gives student their average grade
****************************************************************/
void computeAverage (Student data[][MAX], const int size[SECTIONS])
{   
    float sum, avg;

    for (int i = 0; i < SECTIONS; i++)
    {

        for (int j = 0; j < MAX; j++)
        {
            // Reset values for each student
            sum = 0;
            avg = 0;

            // Sums up all grades for one student
            sum += data[i][j].mLab;
            sum += data[i][j].mPa;
            sum += data[i][j].mQuiz;
            sum += data[i][j].mMidterm;
            sum += data[i][j].mFinal;

            // Calculates the average and store it in the student array
            avg = sum / GRADES;
            data[i][j].mAverage = avg;
        }   
    }
    return;
}

/* Function:   computeAverage (Student, const int, double)
*   Purpose:   calculates the class average
*       Pre:   each student must already have their average
*      Post:   gves a class their combined average grade
****************************************************************/
void computeAverage (const Student data[][MAX], const int size[SECTIONS], double averages[SECTIONS])
{
    float sum, avg;
    int i, j;

    for (i = 0; i < SECTIONS; i++)
    {
        // Reset values for each section
        sum = 0;
        avg = 0;

        for (j = 0; j < size[i]; j++)
        {
            // Sums up all grades for one section
            sum += data[i][j].mAverage;

            // Calculates the average and store it in the student array
        }  

        avg = sum / GRADES;
        averages[i] = avg;
    }
    return;
}

/* Function:   counteGrade (Student, const int, int)
*   Purpose:   count the number of students in each of the letter grade distribution for both sections of the class
*       Pre:   letter grades must already be asigned
*      Post:   displays how many of each student got what letter grade
****************************************************************/
void counteGrade (const Student data[][MAX], const int size[SECTIONS], int letterGrade[GRADE][SECTIONS])
{
     for (int i = 0; i < GRADE; ++i)
    {
        for (int j = 0; j < SECTIONS; ++j)
        {
            letterGrade[i][j] = 0;
        }
    }

    // Iterate through each section and student
    for (int i = 0; i < SECTIONS; ++i)
    {
        for (int j = 0; j < size[i]; ++j)
        {
            // Get student grade and add it to corresponding letter grade
            string studentGrade = data[i][j].mGrade;

            // Increment the corresponding grade count
            if (studentGrade == "A")
            {
                letterGrade[0][i]++;
            }
            else if (studentGrade == "B")
            {
                letterGrade[1][i]++;
            }
            else if (studentGrade == "C")
            {
                letterGrade[2][i]++;
            }
            else if (studentGrade == "D")
            {
                letterGrade[3][i]++;
            }
            else if (studentGrade == "F")
            {
                letterGrade[4][i]++;
            }
        }
    }
}

/* Function:   displayData (Student, const int)
*   Purpose:   prints the data of a student
*       Pre:   Student must be initialized and populated
*      Post:   data is printed to the console
****************************************************************/
void displayData (const Student data[][MAX], const int size[SECTIONS])
{
    // I keep getting a segmentation fault in this function for some reason
    for (int i = 0; i < SECTIONS; i++)
    {
        cout << "SECTION " << i << endl << endl;

        for (int j = 0; j < size[i]; j++)
        {
            //Displays the data of students
            cout << "ID: " << data[i][j].mId << endl;
            cout << "Name: " << data[i][j].mName << endl;
            cout << "Lab: " << data[i][j].mLab << endl;
            cout << "PA: " << data[i][j].mPa << endl;
            cout << "Quiz: " << data[i][j].mQuiz << endl;
            cout << "Midterm: " << data[i][j].mMidterm << endl;
            cout << "Final: " << data[i][j].mFinal << endl;
            cout << "Average: " << data[i][j].mAverage << endl;
            cout << "Grade: " << data[i][j].mGrade << endl << endl;
        }
    }
    return;
}

/* Function:   displayStat (Student, const int, const double, const int)
*   Purpose:   displays the statistical info for each section 
*       Pre:   averages must be calculated and students must be loaded
*      Post:   shows the statistical info of each class section
****************************************************************/
void displayStat (const Student data[][MAX], const int size[SECTIONS], const double averages[SECTIONS], const int letterGrade[GRADE][SECTIONS])
{
     for (int i = 0; i < SECTIONS; ++i)
    {
        float highest = data[i][0].mAverage, lowest = data[i][0].mAverage;

        cout << "SECTION " << i << ":" << endl;
        cout << "Number of Students: " << size[i] << endl;
        cout << "Class Average: " << averages[i] << endl;

        // Find highest and lowest scores
        for (int j = 1; j < size[i]; ++j)
        {
            if (data[i][j].mAverage > highest)
            {
                highest = data[i][j].mAverage;
            }
            if (data[i][j].mAverage < lowest)
            {
                lowest = data[i][j].mAverage;
            }
        }
        cout << "Highest Score: " << highest << endl;
        cout << "Lowest Score: " << lowest << endl;

        // Display letter grade distribution
        cout << "Letter Grade Distribution:" << endl;
        cout << "A: " << letterGrade[0][i] << endl;
        cout << "B: " << letterGrade[1][i] << endl;
        cout << "C: " << letterGrade[2][i] << endl;
        cout << "D: " << letterGrade[3][i] << endl;
        cout << "F: " << letterGrade[4][i] << endl;

        cout << endl;
    }
}

/* Function:   loadDAta (Student, int)
*   Purpose:   initializes all student data into struct array
*       Pre:   Student struct must exist and there must be data in the file
*      Post:   student data is initiated and can now be used
****************************************************************/
void loadData (Student data[][MAX], int size[SECTIONS])
{
    char grade;
    float lab, pa, quiz, midterm, final, average;
    fstream students;
    int i = 0, j = 0;
    string id, name, line;
    Student stu;

    // Open file and check it works
    students.open("students.txt", ios::in);
    if (students.fail())
    {
        cout << "failed to open 'students.tzt'" << endl;
        exit(1);
    }

    while (!students.eof() && i < SECTIONS)
    {
        j = 0;

        while (j < MAX)
        {
            // Check for next section line
            getline(students,line);
            if (NEXT_SECTION == line || students.eof())
            {
                i++;
                break;
            }

            // Get data from file
            id = line;
            getline(students, name);
            students >> lab >> pa >> quiz >> midterm >> final;
            getline(students,line);

            // Write data into struct
            stu.mId = id;
            stu.mName = name;
            stu.mLab = lab;
            stu.mPa = pa;
            stu.mQuiz = quiz;
            stu.mMidterm = midterm;
            stu.mFinal = final;

            // Store struct instance info into array
            data[i][j] = stu;
            j++;
        }
        size[i] = j;
    }
    students.close();
    return;
}

/* Function:   sortData (Student, const int)
*   Purpose:   sort the students based on their average from highest to lowest for both sections of the course
*       Pre:   students must be initialized
*      Post:   students and their data are properly organized
****************************************************************/
void sortData (Student data[][MAX], const int size[SECTIONS])
{
    for (int i = 0; i < SECTIONS; ++i)
    {
        // Bubble sort within each section
        for (int j = 0; j < size[i] - 1; ++j)
        {
            for (int k = 0; k < size[i] - j - 1; ++k)
            {
                // Compare average grades and swap if necessary
                if (data[i][k].mAverage < data[i][k + 1].mAverage)
                {
                    // Swap students
                    Student temp = data[i][k];
                    data[i][k] = data[i][k + 1];
                    data[i][k + 1] = temp;
                }
            }
        }
    }
    return;
}
