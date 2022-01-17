#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node():data{0},next{nullptr}{}
     
};

Node *top = nullptr;

void push(int x)
{
        Node *p;
        p = new Node;
        p->data = x;
        p->next = top;
        top = p;
}
void pop()
{
    if(top==nullptr)
      cout<<"Stack is empty...";
    else{
        Node *p = top;
        top = top->next;
        delete p;
    }
}
void display()
{
    Node *p = top;
    cout<<"stack is \n";
    while(p)
    {
        cout<<p->data<<endl;
        p = p->next;
    }
}

int main()
{
   push(5);
   push(2);
   push(8);
   push(7);
    display();
   pop();
   pop();
   display();
}


