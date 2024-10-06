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
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
        } else {
            Node* currentNode = root;
            while (true) {
                if (currentNode->value > value) {
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

    Node* lookup(int value) {
        if (root == nullptr) {
            return nullptr;
        }

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

    bool remove(int value) {
        if (root == nullptr) {
            return false;
        }

        Node* currentNode = root;
        Node* parentNode = nullptr;

        while (currentNode != nullptr) {
            if (value < currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->left;
            } else if (value > currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->right;
            } else { // Match found
                // Option 1: No right child
                if (currentNode->right == nullptr) {
                    if (parentNode == nullptr) {
                        root = currentNode->left;
                    } else {
                        if (currentNode->value < parentNode->value) {
                            parentNode->left = currentNode->left;
                        } else {
                            parentNode->right = currentNode->left;
                        }
                    }

                // Option 2: Right child with no left child
                } else if (currentNode->right->left == nullptr) {
                    currentNode->right->left = currentNode->left;
                    if (parentNode == nullptr) {
                        root = currentNode->right;
                    } else {
                        if (currentNode->value < parentNode->value) {
                            parentNode->left = currentNode->right;
                        } else {
                            parentNode->right = currentNode->right;
                        }
                    }

                // Option 3: Right child with a left child
                } else {
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
                        if (currentNode->value < parentNode->value) {
                            parentNode->left = leftmost;
                        } else {
                            parentNode->right = leftmost;
                        }
                    }
                }
                delete currentNode;
                return true;
            }
        }
        return false;
    }

    // Helper function to print the tree
    void print(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->value << " ";
        print(node->left);
        print(node->right);
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

    tree.print(tree.root); // Preorder traversal

    if (tree.lookup(20)) {
        cout << "\nNode 20 found!" << endl;
    } else {
        cout << "\nNode 20 not found!" << endl;
    }

    return 0;
}
