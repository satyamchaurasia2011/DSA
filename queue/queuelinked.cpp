#include<iostream>
using namespace std;

class Node
{
    public:
      int data;
      Node *next;
};

class Queue
{
private:
   Node *front;
   Node *rear;
public:
    Queue():front{nullptr},rear{nullptr} {};
    void enqueue(int ele);
    void dequeue();
    bool isEmpty();
    void display();
    
};

bool Queue::isEmpty()
{
    if(front == nullptr)
       return true;
    else
      return false;
}

void Queue::enqueue(int ele)
{
    Node *p = new Node;
    if(p == nullptr)
       cout<<"Queue is full \n";
    else  
      {
          p->data = ele;
          p->next = nullptr;
          if(front == nullptr)
             front=rear=p;
          else
            {
                rear->next = p;
                rear = p;
            }
      }
}

void Queue::dequeue()
{
    Node *p;
    if(isEmpty())
      cout<<"Queue is empty \n";
    else
      {
          p = front;
          front = front->next;
          delete p;
      }
}

void Queue::display()
{
    if(isEmpty())
      cout<<"Queue is empty \n";
    else
      {
          Node *p;
          p = front;
          while(p)
          {
              cout<<p->data<<endl;
              p = p->next;
          }
      }
}

int main()
{
    Queue que;
    que.enqueue(5);
    que.enqueue(32);
    que.enqueue(2);
    que.display();
    return 0;
}