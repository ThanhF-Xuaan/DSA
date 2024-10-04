#include <iostream>
#include <string>

using namespace std;

// Node class to represent an element in the Queue
class Node {
public:
    string value;
    Node* next;

    Node(string val) : value(val), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* first;
    Node* last;
    int length;

public:
    // Constructor to initialize an empty queue
    Queue() : first(nullptr), last(nullptr), length(0) {}

    // Peek method to see the first element of the queue
    Node* peek() {
        return first;
    }

    // Enqueue method to add an element at the end of the queue
    Queue& enqueue(string value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        length++;
        return *this;  // Return the queue object to allow method chaining
    }

    // Dequeue method to remove the first element from the queue
    Queue& dequeue() {
        if (!first) {
            return *this;  // If the queue is empty, do nothing
        }
        if (first == last) {
            last = nullptr;
        }
        Node* temp = first;
        first = first->next;
        delete temp;  // Free the memory of the removed node
        length--;
        return *this;  // Return the queue object to allow method chaining
    }

    // Method to check if the queue is empty
    bool isEmpty() {
        return length == 0;
    }

    // Method to print the contents of the queue
    void printQueue() {
        Node* current = first;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueue("Joy").enqueue("Matt").enqueue("Pavel").enqueue("Samir");
    myQueue.dequeue();  // Remove "Joy"
    
    // Print the contents of the queue
    myQueue.printQueue();  // Expected output: Matt Pavel Samir
    
    // Peek at the first element
    cout << "Peek: " << myQueue.peek()->value << endl;  // Expected output: Matt

    return 0;
}
