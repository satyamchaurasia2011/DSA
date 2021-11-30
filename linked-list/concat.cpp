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

Node * create(Node *n, int num)
{
    n = new Node;
    Node *p = n;
    cout<<"Enter elements \n";
    cin>>p->data;
    Node *s;
    s = p;
    if(num<1)
      p->next = nullptr;
    else{
    for(int i=1; i<num; i++)
    {
        Node *q;
        q = new Node;
        cin>>q->data;
        q->next = nullptr;
        s->next = q;
        s = q;
    }
    
    }
    return n;
}
Node * concat(Node *p, Node *q)
{
    Node *first,*second;
    first=second=nullptr;
    if(p->data>q->data)
    {
        first = second = q;
         q = q->next;
        first->next = nullptr;
    }
    else{
        first = second = p;
          p = p->next;
        first->next = nullptr;
      
    }
    while(p && q)
    {
        if(p->data>q->data)
        {
           // second=first;
            first->next=q;
            first = first->next;
              q = q->next;
            first->next = nullptr;
        }
        else{
            // second=first;
            first->next=p;
            first = first->next;
              p = p->next;
            first->next = nullptr;
          
        }
    }
    while(p)
    {
         first->next=p;
            first = first->next;
              p = p->next;
            first->next = nullptr;

    }
    while(q)
    {
         first->next=q;
            first = first->next;
              q = q->next;
            first->next = nullptr;
    }
    return second;
}
void display(Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
int main()
{
      int m,ele;
  
  Node *ar1, *ar2;
    cout<<"Enter no. of nodes ";
    cin>>m;
    ar1 = create(ar1, m);
    ar2 = create(ar2, m);
    Node * disp = concat(ar1,ar2);
    display(disp);
}