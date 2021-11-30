#include<iostream>
using namespace std;

class Queue
{
private:
   int front;
   int rear;
public:
    int size;
    int *Q;
    Queue():front{-1},rear{-1},size{20},Q{nullptr} {};
    void enqueue(int data);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void display();
    
};
bool Queue::isEmpty()
{
    if(front == rear)
        return true;
    else
      return false;
}
bool Queue::isFull()
{
    if(rear == size-1)
      return true;
    else 
      return false;
}
void Queue::enqueue(int data)
{
    if(isFull())
       cout<<"Queue is full \n";
    else
    {
        Q[++rear] = data;
    }
}
void Queue::dequeue()
{
    if(isEmpty())
       cout<<"Queue is Empty\n";
    else{
        front++;
    }
}
void Queue::display()
{
    if(isEmpty())
      cout<<"Queue is Empty \n";
    else
      {
          for(int i = front+1; i<=rear; i++)
             cout<<Q[i]<<endl;
      }
      cout<<endl;
}
int main()
{
    Queue que;
    cout<<"Enter size of queue ";
    cin>>que.size;
    que.Q = new int[que.size];
    que.enqueue(3);
    que.enqueue(6);
    que.enqueue(1);
     que.enqueue(7);
      que.enqueue(9);
       que.enqueue(10);
    que.display();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.dequeue();
     que.dequeue();
    que.display();
}

