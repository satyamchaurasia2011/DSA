#include<bits/stdc++.h>
using namespace std;

class Circularqueue
{
private:
    int front,rear;
public:
    int size,*Q;
    Circularqueue():front{0},rear{0},size{20},Q{nullptr}{};
     void enqueue(int data);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

bool Circularqueue::isEmpty()
{
    if(front == rear)
       return true;
    else
      return false;
}

bool Circularqueue::isFull()
{
    if((rear+1)%size == front)
      return true;
    else
      return false;
}

void Circularqueue::enqueue(int data)
{
    if(isFull())
       cout<<"Queue is full \n";
    else
    {
        rear = (rear+1)%size;
         Q[rear] = data;
    }
      
}

void Circularqueue::dequeue()
{
    if(isEmpty())
       cout<<"Queue is empty \n";
    else
      front = (++front)%size;
}

void Circularqueue::display()
{
    if(isEmpty())
      cout<<"Queue is empty \n";
    else
      for(int i=front+1; i!=(rear+1)%size; i=(i+1)%size)
         cout<<Q[i]<<endl;

    cout<<endl;
}

int main()
{
    Circularqueue que;
    int p;
     cout<<"Enter size of queue ";
    cin>>p;
    que.size = p+1;
    que.Q = new int[que.size];
    que.enqueue(3);
    que.enqueue(6);
    que.enqueue(1);
    que.dequeue();
    que.enqueue(199);
    que.dequeue();
    que.enqueue(200);
     que.display();
}