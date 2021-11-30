#include<iostream>
using namespace std;

class Node
{
    public:
       int data;
       int height;
       Node *lchild;
       Node *rchild;
       Node():data{0},height{0},lchild{nullptr},rchild{nullptr}{};
};
Node *root=nullptr;

int nodeHeight(Node *p)
{
    int l,r;
    if(p->lchild==nullptr && p->rchild==nullptr)
       return 0;
   l = p && p->lchild ?p->lchild->height : 0;
   r = p && p->rchild? p->rchild->height : 0;
   return l>r?l+1:r+1;
}

int balanceFactor(Node *p)
{
   int l,r;
   l = p && p->lchild ?p->lchild->height+1 : 0;
   r = p && p->rchild? p->rchild->height+1 : 0;
   return l-r;
}

Node *LLRotation(Node *p)
{
    Node *temp = p->lchild;
    Node *temp1 = temp->rchild;

    temp->rchild = p;
    p->lchild = temp1;
    p->height = nodeHeight(p);
    temp->height = nodeHeight(temp);

    if(root == p)
       root = temp;
     return temp;
}

Node *RRRotation(Node *p)
{
    Node *temp = p->rchild;
    Node *temp1 = temp->lchild;

    temp->lchild = p;
    p->rchild = temp1;
    p->height = nodeHeight(p);
    temp->height = nodeHeight(temp);

    if(root = p)
        root = temp;
     return temp;
}

Node *LRRotaion(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
   
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if(root == p)
      root = plr;
    return plr;
}

Node *RLRotaion(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
   
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->lchild = p;
    prl->rchild = pr;

    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);

    if(root == p)
      root = prl;
    return prl;
}


Node *insertNodeInAvl(Node *p, int key)
{
    if(p ==nullptr)
      {
          p = new Node;
          p->data = key;
          return p;
      }
    if(key < p->data)
       p->lchild = insertNodeInAvl(p->lchild, key);
    else if(key > p->data)
       p->rchild = insertNodeInAvl(p->rchild, key);

    p->height = nodeHeight(p);  //calculate height of each node

    if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LLRotation(p);
    
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
         return RRRotation(p);
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LRRotaion(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RLRotaion(p);
    return p;
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
    if(p == nullptr)
       return nullptr;
    if(p->lchild == nullptr && p->rchild == nullptr)
       {
           if(p == root)
              root == nullptr;
            delete p;
            return nullptr;
       }
    if(key < p->data)
       p->lchild = deleteNode(p->lchild, key);
    else if(key > p->data)
       p->rchild = deleteNode(p->rchild, key);
    else
      {
          if(p->lchild->height > p->rchild->height)
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
       if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
         return LLRotation(p);
    
         else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
              return RRRotation(p);
        else if(balanceFactor(p) == 2 && (balanceFactor(p->lchild) == -1 || balanceFactor(p->lchild) == 0))
             return LRRotaion(p);
         else if(balanceFactor(p) == -2 && (balanceFactor(p->rchild) == 1 || balanceFactor(p->rchild) == 0))
              return RLRotaion(p);
        return p;
}

void postorder(Node *p)
{
    if(p == nullptr)
       return;
    postorder(p->lchild);
    postorder(p->rchild);
    cout<<p->data<<" ";
}
int main()
{
    root = insertNodeInAvl(root, 30);
    insertNodeInAvl(root,10);
    insertNodeInAvl(root, 40);
    insertNodeInAvl(root,5);
    insertNodeInAvl(root,20);
    cout<<"AVL tree is generated \n";
    
    deleteNode(root, 40);
    postorder(root);
    cout<<endl;
    return 0;
}