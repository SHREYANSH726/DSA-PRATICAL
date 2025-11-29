#include <iostream>
using namespace std;

int main() {
    int score;
    cout << "Enter your score (out of 100): ";
    cin >> score;

    // Using ternary operator to determine grade
    char grade = (score >= 90) ? 'A' :
                 (score >= 80) ? 'B' :
                 (score >= 70) ? 'C' :
                 (score >= 60) ? 'D' : 'F';

    cout << "Your grade: " << grade << endl;

    // Step 2: Switch-Case Statement to Provide Additional Comments
    switch(grade) {
        case 'A':
            cout << "Excellent work!" << endl;
            break;
        case 'B':
            cout << "Well done!" << endl;
            break;
        case 'C':
            cout << "Good job!" << endl;
            break;
        case 'D':
            cout << "You passed, but you could do better." << endl;
            break;
        case 'F':
            cout << "Sorry, you failed." << endl;
            break;
    }

    // Step 3: Eligibility Check Using If-Else Statement
    if (grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D') {
        cout << "Congratulations! You are eligible for the next level." << endl;
    } else {
        cout << "Please try again next time." << endl;
    }

    return 0;
}
