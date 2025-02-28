// Task 1 = CGPA Calculator

#include <iostream>
using namespace std;

int main()
{
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    double totalGradePoints = 0, totalCredits = 0;

    for (int i = 0; i < numCourses; i++)
    {
        char grade;
        int credits;
        double gradePoint;

        cout << "\nEnter Grade (A/B/C/D/F) for Course " << i + 1 << ": ";
        cin >> grade;
        cout << "Enter Credit Hours: ";
        cin >> credits;

        if (grade == 'A' || grade == 'a')
            gradePoint = 4.0;
        else if (grade == 'B' || grade == 'b')
            gradePoint = 3.0;
        else if (grade == 'C' || grade == 'c')
            gradePoint = 2.0;
        else if (grade == 'D' || grade == 'd')
            gradePoint = 1.0;
        else if (grade == 'F' || grade == 'f')
            gradePoint = 0.0;
        else
        {
            cout << "Invalid grade! Please restart.\n";
            return 1;
        }

        totalGradePoints += gradePoint * credits;
        totalCredits += credits;
    }

    double CGPA = totalGradePoints / totalCredits;
    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalGradePoints;
    cout << "\nYour CGPA is: " << CGPA << endl;

    return 0;
}