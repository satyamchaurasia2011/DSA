/////////////////////////// PRIORITY QUEUE////////////////////////

#include<iostream>
using namespace std;
////we take highest priority of smaller number.
class Priority
{
    public:
        int *Q;
        int rear;
        int size;
        Priority():Q{nullptr},size{10},rear{-1}{};
        void enqueue(int data);
        void dequeue();
        void display();
};

void Priority::enqueue(int data)
{
    if(rear == size-1)
       cout<<"Queue is full\n";
    else
        Q[++rear] = data;
}
void Priority::dequeue()
{
    if(rear == -1)
       cout<<"Queue is empty";
    else
    {
        int index=0;
        for(int i=1; i<=rear; i++)
         {
             if(Q[index]>Q[i])
                 index = i;
         }
        for(int i=index+1; i<=rear; i++)
           Q[i-1] = Q[i];

        rear--;
    }
}
void Priority::display()
{
    for(int i=0; i<=rear; i++)
      cout<<Q[i]<<endl;
    cout<<endl;
}

int main()
{
    Priority que;
    cout<<"Enter size of queue ";
    cin>>que.size;
    que.Q = new int[que.size];
    que.enqueue(4);
    que.enqueue(7);
    que.enqueue(1);
    que.enqueue(3);
    que.enqueue(7);
    que.enqueue(2);
    que.enqueue(1);
    que.display();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.display();
    return 0;
}