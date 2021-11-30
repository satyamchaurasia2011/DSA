#include<iostream>
using namespace std;

class Node
{
    public:
        int key1;
        int key2;
        Node *first;
        Node *second;
        Node *third;
        
        Node():key1{0},key2{0},first{nullptr},second(nullptr),third{nullptr}{};
};
Node *root;

Node *create23Tree(Node *p, int key)
{
     Node *q;
    if(p == nullptr)
      {
         q = new Node;
         q->key1 = key;
         p = q;
         return p;
      }
    if(key < p->key1 && p->first == nullptr)
     {
         if(p->first == nullptr)
          {
             
          }
     }
}