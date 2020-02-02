#include <iostream>
#include <sstream>
using namespace std;

#define basespace 10

struct Node {
    char key;
    int is_rchild;
    struct Node *left, *right;
};

struct Node* newnode(char key) {
    struct Node* temp = new Node;
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void create(Node** parent, int child) {
    char key;
    Node* curr;
    cin >> key;
    if (key == '/') {
        return;
    }
    if (*parent != NULL) {
        curr = newnode(key);
        if (child == 0) {
            curr->right = *parent;
            (*(*parent)).left = curr;
        } else {
            if ((*(*parent)).right != NULL) {
                curr->right = (*(*parent)).right;
            }
            (*(*parent)).right = curr;
            (*(*parent)).is_rchild = 1;
        }
    } else {
        curr = newnode(key);
        *parent = curr;
    }

    cout << "child of " << curr->key << ": ";
    create(&curr, 0);
    cout << "sibling of " << curr->key << ": ";
    create(&curr, 1);
}

void printtree(Node* root, int space) {
    if (root == NULL)
        return;
    space += basespace;
    printtree(root->right, space);
    cout << endl;
    for (int i = basespace; i < space; i++)
        cout << " ";
    cout << root->key;
    printtree(root->left, space);
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->key << "  ";
    inorder(root->right);
}

void preorder(struct Node* root) {
    Node* curr = root;
    while (curr != NULL) {
        printf("%c  ", curr->key);
        if (curr->left != NULL) {
            curr = curr->left;

        } else if (curr->is_rchild == 1) {
            curr = curr->right;
        } else {
            while (curr->right != NULL && curr->is_rchild == 0)
                curr = curr->right;
            if (curr->right == NULL) {
                break;
            } else {
                curr = curr->right;
            }
        }
    }
}

int main() {
    struct Node* root = NULL;
    create(&root, 0);
    //inorder(root);

    cout << "The preorder of the binary tree : ";
    preorder(root);
    cout << endl;
    return 0;
}
