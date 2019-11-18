#include <iostream>
using namespace std;

class Stack {
    int top, size;

    public:
        int *stack_array;

        Stack(int s){
            size = s;
            stack_array = new int[(size * sizeof(int))];
            top = -1;
        }
        bool push(int x);
        void pop();
        int peek();
        bool isEmpty();
        void display();
};

bool Stack::push(int val) {
    if(top>=size-1){
        cout<<"Cannot add element : Stack Overflow"<<endl; 
    }
    else {
        top++;
        stack_array[top]=val;
    }
}

void Stack::pop() {
    if(top<=-1){
        cout<<"Cannot delete element : Stack Underflow"<<endl;
    }
    else {
        top--;
    }
}

int Stack::peek(){
    if (top<=-1) {
        cout<<"Cannot get element : Stack Underflow"<<endl;
        return 0;
    }
    else {
        return stack_array[top];
    }
}

bool Stack::isEmpty(){
    return (top < 0);
}

void Stack::display() {
    if(top>=0) {
        cout<<"Stack elements are:";
        for(int i=top; i>=0; i--)
            cout<<stack_array[i]<<" ";
        cout<<endl;
    }
    else{
        cout<<"Stack is empty"<<endl;
    }
}

int main() {

    class Stack s(10);
    int ch, val;
    int out;
    bool outstate;
    cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Peek in stack"<<endl;
    cout<<"4) isEmpty of stack"<<endl;
    cout<<"5) Display stack"<<endl;
    cout<<"6) Exit"<<endl;
    do {
        cout<<"Enter choice: "<<endl;
        cin>>ch;
        switch(ch) {
            case 1: {   
                cout<<"Enter value to be pushed:"<<endl;
                cin>>val;
                outstate=s.push(val);
                cout<<"Is element pushed into stack ? : ";
                (outstate==1) ? cout<<"yes" : cout<<"no";
                cout <<endl;
                break;
            }
            case 2: {
                s.pop();
                cout<<"Deleted top element in stack"<<endl;
                break;
            }
            case 3: {
                out = s.peek();
                cout << "Peek element : "<<out<<endl;
                break;
            }
            case 4: {
                outstate = s.isEmpty();
                cout<<"Is stack Empty ? : ";
                (outstate==1) ? cout<<"yes" : cout<<"no";
                cout <<endl;
                break;
            }
            case 5: {
                s.display();
                break;
            }
            case 6: {
                cout<<"Exit"<<endl;
                break;
            }
            default: {
                cout<<"Invalid Choice"<<endl;
            }
        }
    }while(ch!=6);

    return 0;
}
