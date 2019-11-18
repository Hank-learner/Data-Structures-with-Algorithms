#include <iostream>
using namespace std;
class Queue{
	public:
	int *queue;
	int size ,front ,rear;
	void Insert(int val);
	int Delete();
	void Display();
	Queue(int s)
   {
		size = s;
		queue = new int[(size * sizeof(int))];
 		front = - 1;
		rear = - 1;
	}
};

void Queue::Insert(int val) 
{
   if (rear == size - 1) {
      cout<<"Cannot add element : Queue Overflow"<<endl;
   }
   else {
      if (front == - 1)
      front = 0;
      rear++;
      queue[rear] = val;
   }
}

int Queue::Delete() 
{
   if (front == - 1 || front > rear) {
      cout<<"Cannot delete element : Queue Underflow ";
   return 0;
   } 
   else {
      return queue[front++] ;
   }
}

void Queue::Display() 
{
   if (front == - 1) {
   cout<<"Queue is empty"<<endl;
   }
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
         cout<<queue[i]<<" ";
      cout<<endl;
   }
}

// Driver program
int main() 
{
	class Queue q(10);

   int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
do {
   cout<<"Enter your choice : "<<endl;
   cin>>ch;
   int val;
   switch (ch) {
      case 1:
	  	   cout<<"Enter value of element to add to queue : "<<endl;
      	   cin>>val;
	  	   q.Insert(val);
           break;
      case 2:
	  	   val=q.Delete();
	  	   cout<<"Element deleted from queue is : "<<val <<endl;
           break;
      case 3:
	  	   q.Display();
           break;
      case 4:
	  	   cout<<"Exit"<<endl;
       	   break;
      default: cout<<"Invalid choice"<<endl;
   }
} while(ch!=4);

   return 0;
}
