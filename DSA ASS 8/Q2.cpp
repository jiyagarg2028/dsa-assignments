#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Recursive search
Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }

    if (root->data < key) {
        return searchRecursive(root->right, key);
    }

    return searchRecursive(root->left, key);
}

// Non-recursive search
Node* searchIterative(Node* root, int key) {
    while (root != nullptr && root->data != key) {
        if (root->data < key) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return root;
}

// Maximum element
Node* maximumElement(Node* root) {
    while (root != nullptr && root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// Minimum element
Node* minimumElement(Node* root) {
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// In-order successor
Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != nullptr) {
        return minimumElement(node->right);
    }

    Node* successor = nullptr;
    while (root != nullptr) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

// In-order predecessor
Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != nullptr) {
        return maximumElement(node->left);
    }

    Node* predecessor = nullptr;
    while (root != nullptr) {
        if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else {
            break;
        }
    }
    return predecessor;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Create sample BST
    //       50
    //      /  \
    //     30   70
    //    /  \ /  \
    //   20 40 60 80
    
    Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    cout << "BST: ";
    inorder(root);
    cout << endl;

    // Search
    int key = 40;
    Node* foundRec = searchRecursive(root, key);
    cout << "\nSearch (Recursive) for " << key << ": ";
    if (foundRec) cout << "Found!" << endl;
    else cout << "Not found!" << endl;

    Node* foundIter = searchIterative(root, key);
    cout << "Search (Iterative) for " << key << ": ";
    if (foundIter) cout << "Found!" << endl;
    else cout << "Not found!" << endl;

    // Maximum
    Node* maxNode = maximumElement(root);
    cout << "\nMaximum element: " << maxNode->data << endl;

    // Minimum
    Node* minNode = minimumElement(root);
    cout << "Minimum element: " << minNode->data << endl;

    // In-order successor
    Node* node = root->left; // node with data 30
    Node* successor = inorderSuccessor(root, node);
    cout << "\nIn-order successor of " << node->data << ": ";
    if (successor) cout << successor->data << endl;
    else cout << "None" << endl;

    // In-order predecessor
    Node* predecessor = inorderPredecessor(root, node);
    cout << "In-order predecessor of " << node->data << ": ";
    if (predecessor) cout << predecessor->data << endl;
    else cout << "None" << endl;

    return 0;
}