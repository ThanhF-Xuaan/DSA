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

    // Method to traverse to a specific index
    Node* traverseToIndex(int index) {
        int counter = 0;
        Node* currentNode = head;
        while (counter != index) {
            currentNode = currentNode->next;
            counter++;
        }
        return currentNode;
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
        Node* leader = traverseToIndex(index - 1); // Get the node before the index
        Node* holdingPointer = leader->next;       // Hold the next node
        leader->next = newNode;                    // Insert new node
        newNode->next = holdingPointer;            // Link new node to the rest

        if (index == length) { // Update tail if inserted at the end
            tail = newNode;
        }

        length++; // Increment the length
    }

    // Method to remove a node at a specified index
    void remove(int index) {
        // Handle invalid index
        if (index < 0 || index >= length) {
            cout << "Index out of bounds" << endl;
            return;
        }

        // Removing the head node
        if (index == 0) {
            Node* unwantedNode = head;
            head = head->next; // Move the head pointer
            delete unwantedNode;
            length--;
            return;
        }

        Node* leader = traverseToIndex(index - 1); // Get the node before the index
        Node* unwantedNode = leader->next;         // The node to be deleted
        leader->next = unwantedNode->next;         // Skip the unwanted node

        // If removing the tail, update the tail pointer
        if (index == length - 1) {
            tail = leader;
        }

        delete unwantedNode; // Delete the node
        length--;            // Decrement the length
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

    myLinkedList.remove(2);       // Remove the node at index 2
    cout << "List after removing node at index 2: ";
    myLinkedList.printList();     // Output: 1 10 5 16

    return 0;
}
