#include <iostream>
#include <vector>
using namespace std;

// Class Template
template <class T>
class MemoryCalculate {
private:
    T id;
    string name;

public:
    // Constructor
    MemoryCalculate(T id, string name) {
        this->id = id;
        this->name = name;
    }

    // Getter for ID
    T getId() {
        return id;
    }

    // Display student details
    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    vector<MemoryCalculate<int>> students;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Remove Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);

            students.push_back(MemoryCalculate<int>(id, name));
            cout << "Student added successfully.\n";
        }

        else if (choice == 2) {
            if (students.empty()) {
                cout << "No students found.\n";
            } else {
                cout << "\nStudent List:\n";
                for (auto &s : students) {
                    s.display();
                }
            }
        }

        else if (choice == 3) {
            int searchId;
            cout << "Enter Student ID to search: ";
            cin >> searchId;

            bool found = false;
            for (auto &s : students) {
                if (s.getId() == searchId) {
                    s.display();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 4) {
            int removeId;
            cout << "Enter Student ID to remove: ";
            cin >> removeId;

            bool removed = false;
            for (auto it = students.begin(); it != students.end(); ++it) {
                if (it->getId() == removeId) {
                    students.erase(it);
                    cout << "Student removed successfully.\n";
                    removed = true;
                    break;
                }
            }
            if (!removed) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 5) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
