#include<iostream>
#include<forward_list>

using namespace std;
class Node
{
    public: 
      int data;
      Node *next;
    Node(){data=0;next=nullptr;};
};
Node *head = nullptr;
int count;
void create(int m)
{
    head = new Node;
    Node *n,*p ;
    n  = head;
    cout<<"Enter data ";
    cin>>n->data;
    n->next = head;
    for(int i=1; i<m; i++)
    {
        p = new Node;
        n->next = p;
        cin>>p->data;
        n = p;
    }
      n->next = head;
}

void display()
{
    Node *p = head;
     count=0;
    cout<<"data is - ";
    do{
        cout<<p->data<<" ";
        count++;
        p = p->next;
    }while(p != head);
}
void insert(int ind, int ele)
{
    Node *p;
     p = new Node;
     p->data = ele;
     Node *q = head;
     cout<<count<<endl;
    if(ind<0 || ind>count)
      return;
     if(ind == 0)
    {
        p->next = head;
        while(q->next != head)
        {
               q = q->next;
        }
         
        q ->next = p;
        head = p;
    }
    else{
        for(int i=0; i<ind-1; i++)
        {
            q =  q -> next; 
        }
        p->next = q->next;
        q->next = p;
    }
}
int main()
{
    int m;
    cout<<"Enter no. of list ";
    cin>>m;
    create(m);
    display();
    int ele,ind;
    cout<<"\ninsert node by input index and element\n";
    cin>>ind>>ele;
    cout<<count<<endl;
    insert(ind,ele);
    display();
}