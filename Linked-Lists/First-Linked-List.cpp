#include <iostream>

using namespace std;

class Node {
public:
    int value;      // Value of the node
    Node* next;     // Pointer to the next node

    // Constructor for Node
    Node(int val) {
        value = val;
        next = nullptr; // Initially, next points to null
    }
};

class LinkedList {
public:
    Node* head;      // Pointer to the head of the linked list
    Node* tail;      // Pointer to the tail of the linked list
    int length;      // Length of the linked list

    // Constructor for LinkedList
    LinkedList(int value) {
        head = new Node(value); // Create the head node
        tail = head;            // The tail is also the head initially
        length = 1;             // Start with length 1
    }

    // Method to append a new value to the linked list
    void append(int value) {
        Node* newNode = new Node(value); // Create a new node

        tail->next = newNode; // Link the current tail to the new node
        tail = newNode;       // Update the tail to the new node
        length++;             // Increment the length
    }

    // Method to print the list for verification
    void printList() {
        Node* currentNode = head; // Start from the head
        while (currentNode != nullptr) {
            cout << currentNode->value << " "; // Print the value
            currentNode = currentNode->next;    // Move to the next node
        }
        cout << endl;
    }

    // Destructor to clean up the linked list
    ~LinkedList() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            Node* temp = currentNode;
            currentNode = currentNode->next; // Move to the next node
            delete temp;                      // Delete the current node
        }
    }
};

int main() {
    LinkedList myLinkedList(10); // Create a linked list with the head value of 10
    myLinkedList.append(5);       // Append 5 to the list
    myLinkedList.append(16);      // Append 16 to the list

    // Print the list to check the structure
    myLinkedList.printList();     // Output: 10 5 16

    return 0;
}
