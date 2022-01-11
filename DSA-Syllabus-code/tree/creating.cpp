#include<iostream>
#include<queue>
#include<stack>
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
void create()
{
    int x;
    Node *p,*q;
    queue<Node*>que;
    cout<<"Enter root value ";
    cin>>x;
    root = new Node;
    root->data = x;
    que.emplace(root);
    while(!que.empty())
    {
         p = que.front();
        que.pop();
         cout<<"Enter value of left child of "<<p->data<<" if u dont want then enter -1 ";
         cin>>x;
         if(x != -1){
            q = new Node;
            q->data = x;
            p->lchild = q;
            que.emplace(q);
        }
        cout<<"Enter value of right child of "<<p->data<<" if u don't want then enter -1 ";
        cin>>x;
        if(x!=-1)
        {
            q = new Node;
            q->data = x;
            p->rchild = q;
            que.emplace(q);
        }
    }
   
}
/////////////RECURSIVE TREE TRAVERSAL //////////////////////////////
// void preorder(Node *p)
// {
//     if(p == nullptr)
//       return;
//     cout<<p->data<<" ";
//     preorder(p->lchild);
//     preorder(p->rchild);
// }
// void inorder(Node *p)
// {
//     if(p == nullptr)
//       return;
//     inorder(p->lchild);
//     cout<<p->data<<" ";
//     inorder(p->rchild);
// }
// void postorder(Node *p)
// {
//      if(p == nullptr)
//       return;
//     postorder(p->lchild);
//     postorder(p->rchild);
//     cout<<p->data<<" ";
// }

/////////////////// ITERATIVE  TREE   TRAVERSALS  ///////////////////////
void preorder(Node *p)
{
    stack<Node*>st;
    while(p!=nullptr || !st.empty())
    {
        if(p)
        {
            cout<<p->data<<" ";
            st.push(p);
            p = p->lchild;
        }
        else{
            p = st.top();
            st.pop();
            p = p->rchild;
        }
    }
}
void inorder(Node *p)
{
     stack<Node*>st;
    while(p!=nullptr || !st.empty())
    {
        if(p)
        {
            st.push(p);
            p = p->lchild;
        }
        else{
            p = st.top();
            st.pop();
            cout<<p->data<<" ";
            p = p->rchild;
        }
    }
}
void postorder(Node *p)
{
      stack<Node*>st;
     Node *temp=nullptr;
    while(p!=nullptr || !st.empty())
    {
        if(p)
        {
            st.push(p);
            p = p->lchild;
        }
        else{
            p = st.top();
            if(p->rchild==nullptr || p->rchild ==temp)
            {
                temp = p;
                st.pop();
                cout<<p->data<<" ";
                p=nullptr;
            }
               else
                 p = p->rchild;
              
        }
    }
}
void levelorder(Node *temp)
{
    queue<Node*>que;
    que.emplace(temp);
    while(!que.empty())
    {
        temp = que.front();
        que.pop();
        cout<<temp->data<<" ";
        if(temp->lchild)
           que.emplace(temp->lchild);
        if(temp->rchild)
          que.emplace(temp->rchild);
    }
}

int main()
{
    create();
    cout<<"preorder traversal is - \n";
    preorder(root);
    cout<<"\ninorder traversal is - \n";
    inorder(root);
    cout<<"\npostorder traversal is - \n";
    postorder(root);
    cout<<"\nlevelorder traversal is - \n";
    levelorder(root);
    cout<<endl;
    return 0;
}