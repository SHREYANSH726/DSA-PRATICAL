#include <iostream>
using namespace std;

// Abstract Base Class (Inheritance + Polymorphism)
class StackBase {
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void topElement() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};

// Derived Class
class Stack : public StackBase {
private:
    int* arr;
    int top;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Push operation
    void push(int value) override {
        if (isFull()) {
            cout << "Stack is FULL! Cannot push.\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack.\n";
    }

    // Pop operation
    void pop() override {
        if (isEmpty()) {
            cout << "Stack is EMPTY! Cannot pop.\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n";
    }

    // Display top element
    void topElement() override {
        if (isEmpty()) {
            cout << "Stack is EMPTY.\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    // Check empty
    bool isEmpty() override {
        return top == -1;
    }

    // Check full
    bool isFull() override {
        return top == capacity - 1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }
};

// Main Function
int main() {
    int size, choice, value;

    cout << "Enter stack size: ";
    cin >> size;

    StackBase* stack = new Stack(size);  // Polymorphism

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Top\n";
        cout << "4. Check Empty\n";
        cout << "5. Check Full\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            stack->push(value);
            break;
        case 2:
            stack->pop();
            break;
        case 3:
            stack->topElement();
            break;
        case 4:
            cout << (stack->isEmpty() ? "Stack is EMPTY\n" : "Stack is NOT EMPTY\n");
            break;
        case 5:
            cout << (stack->isFull() ? "Stack is FULL\n" : "Stack is NOT FULL\n");
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    delete stack;
    return 0;
}
