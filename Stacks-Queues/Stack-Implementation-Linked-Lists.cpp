#include <iostream>
#include <string>
using namespace std;

// Node class to represent each element in the stack
class Node {
public:
    string value;
    Node* next;

    Node(string val) {
        value = val;
        next = nullptr;
    }
};

// Stack class with push, pop, and peek methods
class Stack {
private:
    Node* top;
    Node* bottom;
    int length;

public:
    // Constructor to initialize an empty stack
    Stack() {
        top = nullptr;
        bottom = nullptr;
        length = 0;
    }

    // Peek method to return the value of the top element without removing it
    Node* peek() {
        return top;
    }

    // Push method to add an element to the top of the stack
    void push(string value) {
        Node* newNode = new Node(value);

        if (length == 0) {
            top = newNode;
            bottom = newNode;
        } else {
            Node* holdingPointer = top;
            top = newNode;
            top->next = holdingPointer;
        }
        length++;
    }

    // Pop method to remove the top element and return its value
    void pop() {
        if (!top) {
            cout << "Stack is empty!" << endl;
            return;
        }
        if (top == bottom) {
            bottom = nullptr;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
        length--;
    }

    // isEmpty method to check if the stack is empty
    bool isEmpty() {
        return length == 0;
    }

    // Display stack elements (optional utility function)
    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack myStack;

    myStack.push("google");
    myStack.push("google2");

    cout << "Top element: " << myStack.peek()->value << endl;  // Peek at the top element

    myStack.pop();  // Remove the top element

    cout << "Top element after pop: " << myStack.peek()->value << endl;

    myStack.pop();  // Remove the next element

    if (myStack.isEmpty()) {
        cout << "Stack is empty now!" << endl;
    }

    return 0;
}
