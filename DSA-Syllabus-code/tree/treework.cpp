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
    cout<<"Enter value of root node ";
    cin>>x;
    root = new Node;
    root->data=x;
    que.emplace(root);
    while(!que.empty())
    {
        p = que.front();
        que.pop();
        cout<<"Enter left child of "<<p->data<<" if u don't want enter -1 ";
        cin>>x;
        if(x!=-1)
        {
            q = new Node;
            q->data = x;
            p->lchild = q;
            que.emplace(q);
        }
        cout<<"Enter right child of "<<p->data<<" if u don't want enter -1 ";
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

int countNodes(Node *p)
{
    if(p)
    {
        return countNodes(p->lchild)+countNodes(p->rchild)+1;
    }
    return 0;   
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
int main()
{
    create();
    cout<<"Total no. of node is "<<countNodes(root)<<endl;
    cout<<"Height of a tree is "<<height(root)<<endl;
    return 0;
}