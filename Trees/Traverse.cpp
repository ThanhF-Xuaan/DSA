#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Insert function
    void insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
        } else {
            Node* currentNode = root;
            while (true) {
                if (value < currentNode->value) {
                    // Left
                    if (currentNode->left == nullptr) {
                        currentNode->left = newNode;
                        return;
                    }
                    currentNode = currentNode->left;
                } else {
                    // Right
                    if (currentNode->right == nullptr) {
                        currentNode->right = newNode;
                        return;
                    }
                    currentNode = currentNode->right;
                }
            }
        }
    }

    // Lookup function
    Node* lookup(int value) {
        if (root == nullptr) return nullptr;

        Node* currentNode = root;
        while (currentNode != nullptr) {
            if (value < currentNode->value) {
                currentNode = currentNode->left;
            } else if (value > currentNode->value) {
                currentNode = currentNode->right;
            } else {
                return currentNode;
            }
        }
        return nullptr;
    }

    // Remove function
    bool remove(int value) {
        if (root == nullptr) return false;

        Node* currentNode = root;
        Node* parentNode = nullptr;

        while (currentNode != nullptr) {
            if (value < currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->left;
            } else if (value > currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->right;
            } else {
                // Node found
                // Case 1: No right child
                if (currentNode->right == nullptr) {
                    if (parentNode == nullptr) {
                        root = currentNode->left;
                    } else {
                        if (parentNode->value > currentNode->value) {
                            parentNode->left = currentNode->left;
                        } else {
                            parentNode->right = currentNode->left;
                        }
                    }
                }
                // Case 2: Right child with no left child
                else if (currentNode->right->left == nullptr) {
                    currentNode->right->left = currentNode->left;
                    if (parentNode == nullptr) {
                        root = currentNode->right;
                    } else {
                        if (parentNode->value > currentNode->value) {
                            parentNode->left = currentNode->right;
                        } else {
                            parentNode->right = currentNode->right;
                        }
                    }
                }
                // Case 3: Right child with a left child
                else {
                    Node* leftmost = currentNode->right->left;
                    Node* leftmostParent = currentNode->right;
                    while (leftmost->left != nullptr) {
                        leftmostParent = leftmost;
                        leftmost = leftmost->left;
                    }
                    leftmostParent->left = leftmost->right;
                    leftmost->left = currentNode->left;
                    leftmost->right = currentNode->right;

                    if (parentNode == nullptr) {
                        root = leftmost;
                    } else {
                        if (parentNode->value > currentNode->value) {
                            parentNode->left = leftmost;
                        } else {
                            parentNode->right = leftmost;
                        }
                    }
                }
                return true;
            }
        }
        return false;
    }

    // Traverse function
    void traverse(Node* node) {
        if (node != nullptr) {
            cout << node->value << " ";
            traverse(node->left);
            traverse(node->right);
        }
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    BinarySearchTree tree;
    tree.insert(9);
    tree.insert(4);
    tree.insert(6);
    tree.insert(20);
    tree.insert(170);
    tree.insert(15);
    tree.insert(1);
    tree.remove(170);

    tree.traverse(tree.getRoot());  // Output: 9 4 1 6 20 15
    cout << endl;

    Node* foundNode = tree.lookup(20);
    if (foundNode != nullptr) {
        cout << "Node found: " << foundNode->value << endl;
    } else {
        cout << "Node not found" << endl;
    }

    return 0;
}
