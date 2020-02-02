#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
    Node(int);
};

Node::Node(int val) {
    data = val;
    next = prev = NULL;
}

class HugeIntLL {
   public:
    HugeIntLL();
    ~HugeIntLL();

    void insertInFront(int);
    void insertInEnd(int);
    void display();
    int length();
    void add(HugeIntLL*, HugeIntLL*);
    void mul(HugeIntLL*, HugeIntLL*);
    void dif(HugeIntLL*, HugeIntLL*);
    void quo(HugeIntLL*, HugeIntLL*);
    int cmp(HugeIntLL*, HugeIntLL*);
    Node* head;
    Node* tail;
    int size;
};

HugeIntLL::HugeIntLL() {
    head = tail = NULL;
    size = 0;
}

void HugeIntLL::insertInFront(int value) {
    Node* temp = new Node(value);
    if (head == NULL)
        head = tail = temp;
    else {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    size++;
}

void HugeIntLL::insertInEnd(int value) {
    Node* temp = new Node(value);
    if (tail == NULL)
        head = tail = temp;
    else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    size++;
}

void HugeIntLL::display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
    }
}

int HugeIntLL::length() {
    return size;
}

void HugeIntLL::add(HugeIntLL* a, HugeIntLL* b) {
    int c = 0, s;
    HugeIntLL* a1 = new HugeIntLL(*a);
    HugeIntLL* b1 = new HugeIntLL(*b);

    this->head = NULL;
    this->tail = NULL;
    this->size = 0;

    while (a1->tail != NULL || b1->tail != NULL) {
        if (a1->tail != NULL && b1->tail != NULL) {
            s = ((a1->tail->data) + (b1->tail->data) + c) % 10;
            c = ((a1->tail->data) + (b1->tail->data) + c) / 10;
            a1->tail = a1->tail->prev;
            b1->tail = b1->tail->prev;
        } else if (a1->tail == NULL && b1->tail != NULL) {
            s = ((b1->tail->data) + c) % 10;
            c = ((b1->tail->data) + c) / 10;
            b1->tail = b1->tail->prev;
        } else if (a1->tail != NULL && b1->tail == NULL) {
            s = ((a1->tail->data) + c) % 10;
            c = ((a1->tail->data) + c) / 10;
            a1->tail = a1->tail->prev;
        }

        insertInFront(s);
    }

    if (c != 0)
        insertInFront(c);
}

int HugeIntLL::cmp(HugeIntLL* a, HugeIntLL* b) {
    if (a->size != b->size)
        return ((a->size > b->size) ? 1 : 0);

    HugeIntLL* a1 = new HugeIntLL(*a);
    HugeIntLL* b1 = new HugeIntLL(*b);
    while (a1->head != NULL && b1->head != NULL) {
        if (a1->head->data > b1->head->data)
            return 1;
        else if (a1->head->data < b1->head->data)
            return 0;
        else {
            a1->head = a1->head->next;
            b1->head = b1->head->next;
        }
    }
    return 2;
}

int main() {
    string s1, s2;

    HugeIntLL* m = new HugeIntLL();
    HugeIntLL* n = new HugeIntLL();
    HugeIntLL* s = new HugeIntLL();
    HugeIntLL* p = new HugeIntLL();
    HugeIntLL* d = new HugeIntLL();
    HugeIntLL* q = new HugeIntLL();

    cout << "Enter number 1 : ";
    cin >> s1;
    cout << "Enter number 2 : ";
    cin >> s2;

    for (int i = 0; i < s1.length(); i++)
        m->insertInEnd(s1.at(i) - '0');

    for (int i = 0; i < s2.length(); i++)
        n->insertInEnd(s2.at(i) - '0');

    HugeIntLL* m1 = new HugeIntLL(*m);
    HugeIntLL* n1 = new HugeIntLL(*n);
    HugeIntLL* m2 = new HugeIntLL(*m);
    HugeIntLL* n2 = new HugeIntLL(*n);
    HugeIntLL* m3 = new HugeIntLL(*m);
    HugeIntLL* n3 = new HugeIntLL(*n);

    cout << "sum of the two big numbers : ";
    p->add(m1, n1);
    p->display();
    cout << endl;
    return 0;
}
