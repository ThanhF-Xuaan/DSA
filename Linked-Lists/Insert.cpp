#include <iostream>

using namespace std;

// Node class definition
class Node {
public:
    int value;      // Value of the node
    Node* next;     // Pointer to the next node

    // Constructor for Node
    Node(int val) {
        value = val;
        next = nullptr; // Initialize next to nullptr
    }
};

// LinkedList class definition
class LinkedList {
public:
    Node* head;      // Pointer to the head of the linked list
    Node* tail;      // Pointer to the tail of the linked list
    int length;      // Length of the linked list

    // Constructor for LinkedList
    LinkedList(int value) {
        head = new Node(value); // Create the head node
        tail = head;            // Tail is also the head initially
        length = 1;             // Start with length 1
    }

    // Method to append a new value to the linked list
    void append(int value) {
        Node* newNode = new Node(value); // Create a new node
        tail->next = newNode; // Link the current tail to the new node
        tail = newNode;       // Update the tail to the new node
        length++;             // Increment the length
    }

    // Method to prepend a new value to the linked list
    void prepend(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = head;             // Link new node to the current head
        head = newNode;                   // Update head to the new node
        length++;                         // Increment the length
    }

    // Method to insert a new value at a specified index
    void insert(int index, int value) {
        // Handle invalid index
        if (index < 0 || index > length) {
            cout << "Index out of bounds" << endl;
            return;
        }

        // Inserting at the beginning
        if (index == 0) {
            prepend(value);
            return;
        }

        Node* newNode = new Node(value); // Create a new node
        Node* currentNode = head;
        Node* previousNode = nullptr;

        // Traverse to the position to insert
        for (int i = 0; i < index; i++) {
            previousNode = currentNode;  // Keep track of the previous node
            currentNode = currentNode->next; // Move to the next node
        }

        // Insert the new node
        previousNode->next = newNode; // Link the previous node to the new node
        newNode->next = currentNode;   // Link the new node to the current node

        // Update tail if we insert at the end
        if (index == length) {
            tail = newNode; // Update tail if we're adding at the end
        }

        length++; // Increment the length
    }

    // Method to print the linked list
    void printList() {
        Node* currentNode = head; // Start from the head
        while (currentNode != nullptr) {
            cout << currentNode->value << " "; // Print the value
            currentNode = currentNode->next;    // Move to the next node
        }
        cout << endl; // Newline for better output formatting
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
    myLinkedList.prepend(1);      // Prepend 1 to the list

    cout << "List after prepending and appending: ";
    myLinkedList.printList();     // Output: 1 10 5 16

    myLinkedList.insert(2, 99);   // Insert 99 at index 2
    cout << "List after inserting 99 at index 2: ";
    myLinkedList.printList();     // Output: 1 10 99 5 16

    myLinkedList.insert(20, 88);  // Attempt to insert at an invalid index
    cout << "List after attempting to insert at an invalid index: ";
    myLinkedList.printList();     // Output: Index out of bounds and the list remains unchanged

    return 0;
}
