#include <iostream>
using namespace std;

int main() {
    char ch = 'a';

    do {
        cout << ch;
        if (ch + 4 <= 'z') {      // to control last comma
            cout << ", ";
        }
        ch = ch + 4;              // skip 3 alphabets
    } while (ch <= 'z');

    return 0;
}
