#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insert_at_beginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "Inserted at beginning: " << data << endl;
    }

    // Append node at end
    void append(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Search element
    void search(int key) {
        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element " << key << " found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Element " << key << " not found." << endl;
    }

    // Delete node by value
    void delete_node(int key) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted: " << key << endl;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL && curr->next->data != key) {
            curr = curr->next;
        }

        if (curr->next == NULL) {
            cout << "Element not found." << endl;
            return;
        }

        Node* delNode = curr->next;
        curr->next = delNode->next;
        delete delNode;
        cout << "Node deleted: " << key << endl;
    }

    // Reverse linked list
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        cout << "Linked list reversed successfully." << endl;
    }
};

// Main function
int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Append\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Delete Node\n";
        cout << "6. Reverse List\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insert_at_beginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.append(value);
            break;

        case 3:
            list.display();
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;

        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            list.delete_node(value);
            break;

        case 6:
            list.reverse();
            break;

        case 7:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
