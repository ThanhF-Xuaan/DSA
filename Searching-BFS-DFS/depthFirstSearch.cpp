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
        Node* currentNode = root;
        while (currentNode) {
            if (value < currentNode->value) {
                currentNode = currentNode->left;
            } else if (value > currentNode->value) {
                currentNode = currentNode->right;
            } else {
                return currentNode; // Found
            }
        }
        return nullptr; // Not found
    }

    bool remove(int value) {
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
                // Match found
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
                return true;
            }
        }
        return false; // Not found
    }

    vector<int> BreadthFirstSearch() {
        vector<int> list;
        queue<Node*> queue;
        queue.push(root);

        while (!queue.empty()) {
            Node* currentNode = queue.front();
            queue.pop();
            if (currentNode) {
                list.push_back(currentNode->value);
                if (currentNode->left) {
                    queue.push(currentNode->left);
                }
                if (currentNode->right) {
                    queue.push(currentNode->right);
                }
            }
        }
        return list;
    }

    vector<int> DFSInOrder() {
        vector<int> list;
        traverseInOrder(root, list);
        return list;
    }

    vector<int> DFSPreOrder() {
        vector<int> list;
        traversePreOrder(root, list);
        return list;
    }

    vector<int> DFSPostOrder() {
        vector<int> list;
        traversePostOrder(root, list);
        return list;
    }

private:
    void traverseInOrder(Node* node, vector<int>& list) {
        if (node) {
            traverseInOrder(node->left, list);
            list.push_back(node->value);
            traverseInOrder(node->right, list);
        }
    }

    void traversePreOrder(Node* node, vector<int>& list) {
        if (node) {
            list.push_back(node->value);
            traversePreOrder(node->left, list);
            traversePreOrder(node->right, list);
        }
    }

    void traversePostOrder(Node* node, vector<int>& list) {
        if (node) {
            traversePostOrder(node->left, list);
            traversePostOrder(node->right, list);
            list.push_back(node->value);
        }
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

    // BFS
    vector<int> bfsResult = tree.BreadthFirstSearch();
    cout << "BFS: ";
    for (int val : bfsResult) {
        cout << val << " ";
    }
    cout << endl;

    // DFS Results
    vector<int> inOrderResult = tree.DFSInOrder();
    cout << "In-Order DFS: ";
    for (int val : inOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> preOrderResult = tree.DFSPreOrder();
    cout << "Pre-Order DFS: ";
    for (int val : preOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> postOrderResult = tree.DFSPostOrder();
    cout << "Post-Order DFS: ";
    for (int val : postOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
