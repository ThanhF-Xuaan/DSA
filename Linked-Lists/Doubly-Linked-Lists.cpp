#include <iostream>

using namespace std;

// Node class definition
class Node {
public:
    int value;
    Node* prev;
    Node* next;

    // Constructor for Node
    Node(int val) {
        value = val;
        prev = nullptr;
        next = nullptr;
    }
};

// DoublyLinkedList class definition
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    int length;

    // Constructor for DoublyLinkedList
    DoublyLinkedList(int value) {
        head = new Node(value);
        tail = head;
        length = 1;
    }

    // Append a new node to the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        newNode->prev = tail;    // Set the previous pointer to the current tail
        tail->next = newNode;    // Link the current tail to the new node
        tail = newNode;          // Update the tail to the new node
        length++;
    }

    // Prepend a new node to the beginning of the list
    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;    // Set the next pointer to the current head
        head->prev = newNode;    // Link the current head's previous pointer to the new node
        head = newNode;          // Update the head to the new node
        length++;
    }

    // Print the linked list
    void printList() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            cout << currentNode->value << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    // Traverse to a specific index
    Node* traverseToIndex(int index) {
        int counter = 0;
        Node* currentNode = head;
        while (counter != index) {
            currentNode = currentNode->next;
            counter++;
        }
        return currentNode;
    }

    // Insert a new node at a specified index
    void insert(int index, int value) {
        if (index >= length) {
            append(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* leader = traverseToIndex(index - 1);  // Node before insertion point
        Node* follower = leader->next;              // Node after insertion point

        leader->next = newNode;                     // Link leader to new node
        newNode->prev = leader;                     // Set new node's previous to leader
        newNode->next = follower;                   // Link new node to follower
        if (follower != nullptr) {
            follower->prev = newNode;               // Set follower's previous to new node
        }

        if (index == length - 1) {                  // Update tail if inserted at the end
            tail = newNode;
        }

        length++;
    }

    // Remove a node at a specified index
    void remove(int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of bounds" << endl;
            return;
        }

        Node* leader = traverseToIndex(index - 1);  // Node before the one to remove
        Node* unwantedNode = leader->next;          // Node to remove

        leader->next = unwantedNode->next;          // Link leader to unwantedNode's next
        if (unwantedNode->next != nullptr) {
            unwantedNode->next->prev = leader;      // Set the next node's previous to leader
        }

        if (index == length - 1) {                  // Update tail if removing the last node
            tail = leader;
        }

        delete unwantedNode;                        // Delete the unwanted node
        length--;
    }

    // Destructor to clean up the linked list
    ~DoublyLinkedList() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            Node* temp = currentNode;
            currentNode = currentNode->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList myLinkedList(10);  // Create a doubly linked list with head value 10

    myLinkedList.append(5);             // Append 5 to the list
    myLinkedList.append(16);            // Append 16 to the list
    myLinkedList.prepend(1);            // Prepend 1 to the list

    cout << "List after append and prepend: ";
    myLinkedList.printList();           // Output: 1 10 5 16

    myLinkedList.insert(2, 99);         // Insert 99 at index 2
    cout << "List after inserting 99 at index 2: ";
    myLinkedList.printList();           // Output: 1 10 99 5 16

    // Uncomment the following lines to remove a node and test other scenarios
    // myLinkedList.remove(2);          // Remove node at index 2
    // cout << "List after removing node at index 2: ";
    // myLinkedList.printList();        // Output: 1 10 5 16

    return 0;
}
