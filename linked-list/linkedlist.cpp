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
Node *n = nullptr;
///////////////////////////////////////////////////////////////////////
void create(int num)
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
}
////////////////////////////////////////////////////////////////////////////
int count(Node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p = p->next;
    }
    return c;
}
///////////////////////////////////////////////////////////////////////////////////
void display(Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
/////////////////////////////////////////////////////////////////////////////////
int max(Node *p)
{
    int num = INT32_MIN;
    while(p)
    {
       if(p->data>num)
       {
           num = p->data;
       }
       p = p->next;
    }
    return num;
}
/////////////////////////////////////////////////////////////////////////////////////
void searching(Node *p, int ele)
{
    Node *m,*q=nullptr;
    m  = p;
    if(m->data == ele)
    {
        cout<<"Data found -> "<<m->data<<endl;
        return;
    }
       
    while(m)
    {
        if(m->data == ele)
          {
              cout<<"Data found -> "<<m->data<<endl;
              q->next = m->next;
              m->next = p;
              n = m;
              break;
          }
             q = m;
             m = m->next;   
    }
    if(m == nullptr)
      cout<<"not fount"<<endl;
}
///////////////////////////////////////////////////////////////////////////////////////
void insertnode(Node *p, int index, int x)
{
    Node *t;
    if(index<0 || index>count(p))
        return ;
    t = new Node;
    t->data = x;
    if(index==0)
    {
          t->next = p;
          n = t;
    }
    else{
        for(int i=0; i<index-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    
}
/////////////////////////////////////////////////////////////////////////////////////////
Node *last=nullptr;
void insertatend(int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = nullptr;
    if(n == nullptr)
       n = last = p;
    else
    {
        last->next = p;
        last = p;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////

void createlistusinginsertion(int m)
{
    cout<<"Enter element ";
    int ele;
    for(int i=0; i<m; i++)
       {
           cin>>ele;
          // insertnode(n,i,ele);
          insertatend(ele);
       }
}
///////////////////////////////////////////////////////////////////////////////////////

void insertinsorted(int ele)
{
    Node *p = n;
    Node *s = new Node;
    s->data = ele;
    if(n->data > ele)
        {
            s->next = n;
            n = s;
        }
    else
    {
        while(p->next!=nullptr)
        {
             if(p->next->data > ele)
            {
                s->next = p->next;
                p->next = s;
                return;
            }
            p = p->next;
        }
        if(p->next == nullptr)
          {
              p->next = s;
              s->next=nullptr;
          }
       
    }
}

///////////////////////////////////////////////////////////////////////////
void deleteNode(int index)
{
    Node *p = n;
    if(index == 1)
    {
        n = p->next;
        delete p;
    }
    else{
        Node *last = nullptr;
        for(int i=0; i<index-1; i++)
        {
            last = p;
            p = p->next;
        }
        last->next = p->next;
        delete p;
    }
}
//////////////////////////////////////////////////////////////////////////
bool isSortedList()
{
    Node *p = n;
    int x = INT32_MIN;
    while(p)
    {
        if(p->data>x)
        {
            x = p->data;
            p = p->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}
///////////////////////////////////////////////////////////////

void deleteDuplicateElement()
{
    Node *p = n;
    Node *q = p->next;
    while(q)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}
void reverseList(int node)
{
    int A[node];
    Node *p = n;
    int i=0;
    while(p)
    {
        A[i++] = p->data;
        p = p->next;
    }
    p = n;
    i = node-1;
    while(p)
    {
        p->data = A[i--];
        p = p->next;
    }
}
void reverseLink()
{
    Node *p,*q,*r;
    p = n;
    q=r=nullptr;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    n = q;
}
void reverseUsingRecursion(Node *q, Node *p)
{
   
    if(p==nullptr)
       n=q;
    else{
         reverseUsingRecursion(p,p->next);
        p->next = q;
    }
   

}
bool isLoop()
{
    Node *p,*q;
  p = q = n;
        do
        {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
        }while(p && q && p!=q);
        

    if( p == q)
      return true;
    else
      return 0;
    
}
int main()
{
    int m,ele;
  
  
    cout<<"Enter no. of nodes ";
    cin>>m;
    //create(n, m);
    createlistusinginsertion(m);
    //display(n);
    // cout<<"Enter element to search ";
    // cin>>ele;
    // searching(n, ele);
    // int ind,val;
    // cout<<"Enter value and index of node ";
    // cin>>val>>ind;
    // insertnode(n, ind, val);
   // insertatend(4);
    Node *t1 = n->next->next;
    Node *t2 =  n->next->next->next->next ;
    t2->next = t1;
    cout<<isLoop()<<endl;
    // insertinsorted(4);
    //deleteNode(2);
   // display(n);
    //cout<<"\nmax element in list is -> "<<max(n);
    // isSortedList()?cout<<"\nsorted list\n":cout<<"\nNot Sorted\n";
   // deleteDuplicateElement();
   //reverseList(m);  //may take more space..
   //reverseLink();
//    reverseUsingRecursion(nullptr,n);
//      display(n);
    return 0;
}
