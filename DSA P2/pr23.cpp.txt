#include <iostream>
using namespace std;

int main() {
    int num, firstDigit, lastDigit, sum;

    cout << "Enter any number: ";
    cin >> num;

    // Make number positive if it is negative
    if (num < 0) num = -num;

    lastDigit = num % 10;          // last digit

    int temp = num;
    while (temp >= 10) {          // loop to get first digit
        temp /= 10;
    }
    firstDigit = temp;            // first digit

    sum = firstDigit + lastDigit;

    cout << "The sum of the first and the last digit: " << sum << endl;
    return 0;
}
