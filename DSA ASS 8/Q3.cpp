#include <iostream>
#include <algorithm>

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

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to delete found
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int maxDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

int minDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    if (root->left == nullptr) {
        return 1 + minDepth(root->right);
    }

    if (root->right == nullptr) {
        return 1 + minDepth(root->left);
    }

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    // Insert operations
    cout << "Inserting elements: 50 30 70 20 40 60 80" << endl;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "\nBST: ";
    inorder(root);
    cout << endl;

    cout << "\nMaximum depth: " << maxDepth(root) << endl;
    cout << "Minimum depth: " << minDepth(root) << endl;

    // Delete operation
    cout << "\nDeleting 30..." << endl;
    root = deleteNode(root, 30);

    cout << "BST after deletion: ";
    inorder(root);
    cout << endl;

    cout << "\nMaximum depth after deletion: " << maxDepth(root) << endl;
    cout << "Minimum depth after deletion: " << minDepth(root) << endl;

    return 0;
}