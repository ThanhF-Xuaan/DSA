#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack {
private:
    vector<string> array;  // Using vector to mimic the behavior of a dynamic array

public:
    // Peek method to return the top element
    string peek() {
        if (!array.empty()) {
            return array.back();  // Return the last element
        }
        return "Stack is empty!";
    }

    // Push method to add an element to the stack
    Stack& push(string value) {
        array.push_back(value);
        return *this;  // Returning the stack object to mimic chaining like in JS
                       // Return a reference to the current object
    }

    // Pop method to remove the top element
    void pop() {
        if (!array.empty()) {
            array.pop_back();
        } else {
            cout << "Stack is empty!" << endl;
        }
    }

    // isEmpty method (optional)
    bool isEmpty() {
        return array.empty();
    }
};

int main() {
    Stack myStack;

    cout << myStack.peek() << endl;  // Peek when stack is empty

    myStack.push("google");
    myStack.push("ztm");
    myStack.push("discord");

    cout << "Top element: " << myStack.peek() << endl;  // Peek at the top element

    myStack.pop();  // Remove "discord"
    cout << "Top element after pop: " << myStack.peek() << endl;

    myStack.pop();  // Remove "ztm"
    myStack.pop();  // Remove "google"
    
    cout << myStack.peek() << endl;  // Peek when stack is empty again

    return 0;
}
