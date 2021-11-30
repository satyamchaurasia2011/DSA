#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *lchild;
        Node *rchild;  
        Node():data{0},lchild{nullptr},rchild{nullptr}{}  
};
Node *root;
Node *insertNode(Node *p, int key)
{
    if(p == nullptr)
     {
         p = new Node;
         p->data = key;
         return p;
     }
    if(key<p->data)
       p->lchild = insertNode(p->lchild,key);
    else if(key>p->data)
       p->rchild = insertNode(p->rchild, key);
    return p;
}

Node *BSearching(Node *p, int key)
{
    while(p)
    {
        if(p->data == key)
          return p;
        else if(key<p->data)
           p = p->lchild;
        else 
          p = p->rchild;
    }
    return nullptr;
}
 void inorder(Node *p)
{
    if(p == nullptr)
      return;
    inorder(p->lchild);
    cout<<p->data<<" ";
    inorder(p->rchild);
}

int height(Node *p)
{
    int x,y;
    if(p)
    {
        x = height(p->lchild);
        y = height(p->rchild);
        if(x>y)
          return x+1;
        else
          return y+1;
    }
    return -1;
}

Node *inPred(Node *p)
{
  while(p && p->rchild)
     p = p->rchild;
  return p;
}

Node *inSucc(Node *p)
{
  while(p && p->lchild)
     p = p->lchild;
  return p;
}

Node *deleteNode(Node *p, int key)
{
  Node *q;
  if(p==nullptr)
     return nullptr;
  if(p->lchild==nullptr && p->rchild ==nullptr && p->data==key)
    {
      if(p==root)
         root = nullptr;
      delete p;
      return nullptr;
    }
  if(key < p->data)
    p->lchild = deleteNode(p->lchild,key);
  else if(key > p->data)
     p->rchild = deleteNode(p->rchild, key);
  else{
     if(height(p->lchild) > height(p->rchild))
       {
         q = inPred(p->lchild);
         p->data = q->data;
         p->lchild = deleteNode(p->lchild, q->data);
       }
      else
      {
             q = inSucc(p->rchild);
         p->data = q->data;
         p->rchild = deleteNode(p->rchild, q->data);
      }
  }
  return p;
}
int main()
{
    root=nullptr;
    int n,del_key;
    int value;
    cout<<"Create a Binary Search Tree "<<endl;
    cout<<"Enter root node - ";
    cin>>value;
    root = insertNode(root,value);
    cout<<"\nEnter total no. of node under root node that you want to insert \n";
    cin>>n;
    int A[n];
    cout<<"Enter values of all node \n";
    for(int i=0; i<n; i++)
      {
           cin>>A[i];
           insertNode(root,A[i]);
      }
      cout<<"BST CREATED  \n\n\n";
      cout<<"Enter a value of a node that you want to delete ";
      cin>>del_key;
      deleteNode(root,del_key);
      cout<<"inorder - ";
      inorder(root);
    //   Node *Src = BSearching(root,srch_val);
    //   if(Src)
    //      cout<<"Node is Found \n";
    // else
    //   cout<<"Not Found !!!\n";
}