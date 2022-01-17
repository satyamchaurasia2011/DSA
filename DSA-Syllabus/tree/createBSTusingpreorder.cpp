////////////////CREATE  BST   USING PRE-ORDER ///////////////////////

#include<iostream>
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
Node *root =nullptr;

void createBst(int pre[], int size)
{
    Node *p,*q;
    int i=0;
    stack<Node*>stk;
    root = new Node;
    root->data = pre[i++];
    p = root;
    while(i<size)
    {
        if(pre[i]<p->data)
        {
            q = new Node;
            q->data = pre[i++];
            p->lchild = q;
            stk.push(p);
            p = q;
        }
        else
        {
            if(stk.empty() || pre[i]<stk.top()->data)
            {
                 q = new Node;
                q->data = pre[i++];
                p->rchild = q;
                p = q;
            }
            else
              {
                  p = stk.top();
                  stk.pop();
              }
        }
    }
}

void inorder(Node *p)
{
    if(p == nullptr)
      return;
    inorder(p->lchild);
    cout<<p->data<<" ";
    inorder(p->rchild);
}

int main()
{
    int n;
    cout<<"Enter size of pre-order list ";
    cin>>n;
    int A[n];
    cout<<"Enter value of nodes \n";
    for(int i=0; i<n; i++)
      cin>>A[i];
    createBst(A,n);
    cout<<"BST CREATED....\n\n";
    inorder(root);
    return 0;
}