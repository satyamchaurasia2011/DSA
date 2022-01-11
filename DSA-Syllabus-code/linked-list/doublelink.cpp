#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *prev;
        Node *next;
          Node():data(0),prev(nullptr),next(nullptr){}
};
Node *head=nullptr;

void create(int m)
{
    Node *temp = new Node;
    head = temp;
    cout<<"Enter data \n";
    cin>>temp->data;
    temp->prev = nullptr;
    temp->next = nullptr;
    for(int i=1; i<m; i++)
    {
        Node *p = new Node;
        cin>>p->data;
        p->next = nullptr;
        temp->next = p;
        p->prev = temp;
        temp = p;
    }
}

void reverse()
{
    Node *p = head;
    Node *temp;
    while(p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p && p->next == nullptr)
             head = p;
    }
}

void display()
{
    Node *p = head;
    cout<<"data is - \n";
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    int m;
    cout<<"Enter no. of nodes ";
    cin>>m;
    create(m);
    display();
    reverse();
    display();
}