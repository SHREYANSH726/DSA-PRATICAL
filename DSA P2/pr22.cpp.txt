#include <iostream>
using namespace std;

int main() {
    int num;
    int count = 0;

    cout << "Enter any number: ";
    cin >> num;

    if (num == 0) {
        count = 1;                 // 0 has one digit
    } else {
        if (num < 0) num = -num;   // handle negative numbers

        while (num != 0) {
            num /= 10;             // remove last digit
            count++;               // increase digit count
        }
    }

    cout << "Total number of digits: " << count << endl;
    return 0;
}
