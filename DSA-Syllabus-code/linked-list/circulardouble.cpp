#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *prev;
        Node *next;
};
Node *head=nullptr;
void create(int m)
{
    Node *p = new Node;
    head = p;
    cout<<"Enter data - ";
    cin>>p->data;
   
    p->prev = head;
    for(int i=1; i<m; i++)
    {
        Node *q = new Node;
        cin>>q->data;
        p->next = q;
        q->prev = p;
        p = q;
    }
     p->next = head;
     head->prev = p;
}

void display()
{
    Node *p = head;
    do
    {
        cout<<p->data<<" ";
        p = p->next;
    } while (p != head);
    cout<<endl;
}

int main()
{
    int m;
    cout<<"Enter no. of nodes ";
    cin>>m;
    create(m);
    display();
}