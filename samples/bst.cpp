#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int basespace = 10;

struct node {
    int key;
    node *left, *right;
};

node* newNode(int item) {
    node* temp;
    temp = (node*)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
}

node* insert(node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        cout << "Same value";
    }

    return node;
}

void printtree(node* root, int space) {
    if (root == NULL)
        return;

    space += basespace;
    printtree(root->right, space);
    cout << endl;
    int i;

    for (i = basespace; i < space; i++)
        cout << " ";

    cout << root->key << "\n";
    printtree(root->left, space);
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

node* deletenode(node* root, int k) {
    if (root == NULL) {
        return root;
    }

    if (root->key > k) {
        root->left = deletenode(root->left, k);
        return root;
    } else if (root->key < k) {
        root->right = deletenode(root->right, k);
        return root;
    }

    if (root->left == NULL) {
        node* temp = root->right;
        delete root;
        return temp;
    } else if (root->right == NULL) {
        node* temp = root->left;
        delete root;
        return temp;
    } else {
        node* succParent = root->right;
        node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        succParent->left = succ->right;
        root->key = succ->key;
        delete succ;
        return root;
    }
}

int main() {
    node* root = NULL;
    int rootval = 0;
    cout << "Enter the root element of the binary search tree :";
    cin >> rootval;
    root = insert(root, rootval);

    while (1) {
        int choice = 0;
        cout << "Enter\n1 for insert \n2for delete\n3 for display\n Enter your choice : ";
        cin >> choice;
        if (choice == 1) {
            int insertval = 0;
            cout << "Enter the element value to insert :";
            cin >> insertval;
            insert(root, insertval);
        } else if (choice == 2) {
            int deleteval = 0;
            cout << "Enter the element value to insert :";
            cin >> deleteval;
            deletenode(root, deleteval);
        } else if (choice == 3) {
            printtree(root, 0);
            cout << endl
                 << "The inorder tree traversal : ";
            inorder(root);
            cout << endl;
        } else {
            break;
        }
    }
    return 0;
}
