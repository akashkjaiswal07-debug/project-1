#include <iostream>
using namespace std;

int main() {
    int courses;
    float grade, credit;
    float totalCredits = 0;
    float totalGradePoints = 0;

    cout << "===== CGPA Calculator =====" << endl;

    cout << "Enter number of courses: ";
    cin >> courses;

    for (int i = 1; i <= courses; i++) {
        cout << "\nCourse " << i << endl;

        cout << "Enter grade point: ";
        cin >> grade;

        cout << "Enter credit hours: ";
        cin >> credit;

        totalCredits = totalCredits + credit;
        totalGradePoints = totalGradePoints + (grade * credit);
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << "\n===== Result =====" << endl;
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}
