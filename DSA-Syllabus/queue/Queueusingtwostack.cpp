///////////////////////QUEUE   USING    TWO    STACK    ///////////////////////////////////

#include<iostream>
#include<stack>
using namespace std;
stack<int>stk1;
stack<int>stk2;
void enqueue(int data)
{
    stk1.push(data);
}
int dequeue()
{
    int x;
    if(stk2.empty())
       {
           if(stk1.empty())
           {
                 cout<<"Queue is empty";
                 return -1;
           }
           
           else
             {
                 while(!stk1.empty())
                 {
                     stk2.push(stk1.top());
                     stk1.pop();
                 }
             }
       }

       x = stk2.top();
       stk2.pop();
       return x;
}

int main()
{
    enqueue(3);
    enqueue(5);
    enqueue(6);
    enqueue(8);
    enqueue(2);
    enqueue(1);
    enqueue(23);
    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
}

