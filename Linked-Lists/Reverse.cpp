#include <iostream>
#include <vector>

using namespace std;

// Node class definition
class Node {
public:
    int value;
    Node* next;

    // Constructor for Node
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

// LinkedList class definition
class LinkedList {
public:
    Node* head;
    Node* tail;
    int length;

    // Constructor for LinkedList
    LinkedList(int value) {
        head = new Node(value);
        tail = head;
        length = 1;
    }

    // Append a new node to the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
        length++;
    }

    // Prepend a new node to the beginning of the list
    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    // Print the linked list
    vector<int> printList() {
        vector<int> result;
        Node* currentNode = head;
        while (currentNode != nullptr) {
            result.push_back(currentNode->value);
            currentNode = currentNode->next;
        }
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
        return result;
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
        Node* leader = traverseToIndex(index - 1);
        Node* holdingPointer = leader->next;

        leader->next = newNode;
        newNode->next = holdingPointer;
        length++;
    }

    // Remove a node at a specified index
    void remove(int index) {
        Node* leader = traverseToIndex(index - 1);
        Node* unwantedNode = leader->next;
        leader->next = unwantedNode->next;
        delete unwantedNode;
        length--;
    }

    // Reverse the linked list
    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* first = head;
        tail = head;  // Update tail to the current head
        Node* second = first->next;

        while (second) {
            Node* temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }

        head->next = nullptr;  // Set the old head's next to nullptr
        head = first;          // Update the head to the new head (last node)
    }

    // Destructor to clean up the linked list
    ~LinkedList() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            Node* temp = currentNode;
            currentNode = currentNode->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList myLinkedList(10);
    myLinkedList.append(5);        // Append 5 to the list
    myLinkedList.append(16);       // Append 16 to the list
    myLinkedList.prepend(1);       // Prepend 1 to the list

    cout << "List after append and prepend: ";
    myLinkedList.printList();      // Output: 1 10 5 16

    myLinkedList.insert(2, 99);    // Insert 99 at index 2
    cout << "List after inserting 99 at index 2: ";
    myLinkedList.printList();      // Output: 1 10 99 5 16

    myLinkedList.remove(2);        // Remove node at index 2
    cout << "List after removing node at index 2: ";
    myLinkedList.printList();      // Output: 1 10 5 16

    myLinkedList.reverse();        // Reverse the linked list
    cout << "List after reversing: ";
    myLinkedList.printList();      // Output: 16 5 10 1

    return 0;
}
