#include <iostream>
#include <queue>
#include <vector>

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

    Node* lookup(int value) {
        if (root == nullptr) return nullptr;
        Node* currentNode = root;

        while (currentNode) {
            if (value < currentNode->value) {
                currentNode = currentNode->left;
            } else if (value > currentNode->value) {
                currentNode = currentNode->right;
            } else {
                return currentNode; // Found the value
            }
        }
        return nullptr; // Value not found
    }

    bool remove(int value) {
        if (root == nullptr) return false;
        Node* currentNode = root;
        Node* parentNode = nullptr;

        while (currentNode) {
            if (value < currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->left;
            } else if (value > currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->right;
            } else {
                // Value found, perform deletion

                // Case 1: No right child
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

                // Case 2: Right child has no left child
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

                // Case 3: Right child has a left child
                } else {
                    Node* leftmost = currentNode->right->left;
                    Node* leftmostParent = currentNode->right;
                    while (leftmost->left != nullptr) {
                        leftmostParent = leftmost;
                        leftmost = leftmost->left;
                    }

                    // Parent's left subtree is now leftmost's right subtree
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
                return true;
            }
        }
        return false;
    }

    vector<int> BreadthFirstSearch() {
        vector<int> list;
        if (root == nullptr) return list;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* currentNode = q.front();
            q.pop();
            list.push_back(currentNode->value);
            if (currentNode->left) {
                q.push(currentNode->left);
            }
            if (currentNode->right) {
                q.push(currentNode->right);
            }
        }
        return list;
    }

    vector<int> BreadthFirstSearchR(queue<Node*> q, vector<int> list) {
        if (q.empty()) {
            return list;
        }
        Node* currentNode = q.front();
        q.pop();
        list.push_back(currentNode->value);

        if (currentNode->left) {
            q.push(currentNode->left);
        }
        if (currentNode->right) {
            q.push(currentNode->right);
        }

        return BreadthFirstSearchR(q, list);
    }
};

void traverse(Node* node) {
    if (node != nullptr) {
        cout << node->value << " ";
        traverse(node->left);
        traverse(node->right);
    }
}

int main() {
    BinarySearchTree tree;
    tree.insert(9);
    tree.insert(4);
    tree.insert(6);
    tree.insert(20);
    tree.insert(170);
    tree.insert(15);
    tree.insert(1);

    vector<int> bfsResult = tree.BreadthFirstSearch();
    cout << "BFS: ";
    for (int val : bfsResult) {
        cout << val << " ";
    }
    cout << endl;

    queue<Node*> queue;
    queue.push(tree.root);
    vector<int> bfsRecursiveResult = tree.BreadthFirstSearchR(queue, {});
    cout << "BFS (Recursive): ";
    for (int val : bfsRecursiveResult) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Tree Structure (Pre-order Traversal): ";
    traverse(tree.root); // Display tree structure
    cout << endl;

    return 0;
}
