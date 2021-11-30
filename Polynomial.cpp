#include<iostream>
using namespace std;

class Variable
{
    public:
    int exp,coeff;
};
class Polynomial
{
    int n;
  
    public:
      Variable *v;
      Polynomial(int n)
      {
          this->n = n;
          v = new  Variable[n];
      }
};
int main()
{
    int m,n;
    cout<<"Enter no. of terms in polynomial 1 & 2 :";
    cin>>m>>n;
    Polynomial p1(m);
    Polynomial p2(n);
    Polynomial p3(m+n);
    cout<<"Enter coeff and exp of 1st polynomial - \n";
    for(int i=0; i<m; i++)
       cin>>p1.v[i].coeff>>p1.v[i].exp;
    cout<<"Enter coeff and exp of 2nd polynomial - \n";
     for(int i=0; i<n; i++)
       cin>>p2.v[i].coeff>>p2.v[i].exp;
    int j,k,l;
    j=k=l=0;
    while(j<m && k<n)
    {
        if(p1.v[j].exp < p2.v[k].exp)
           p3.v[l++] = p2.v[k++];
        else if(p1.v[j].exp > p2.v[k].exp)
           p3.v[l++] = p1.v[j++];
        else 
         {
             p3.v[l].exp = p1.v[j].exp;
             p3.v[l++].coeff = p1.v[j++].coeff + p2.v[k++].coeff;
             
         }
    }
    for(;j<m; j++)
      p3.v[l++] = p1.v[j];
    for(;k<n; k++)
      p3.v[l++] = p2.v[k];
    
    for(int i=0; i<l; i++)
    {
        cout<<p3.v[i].coeff<<"x"<<p3.v[i].exp<<" + ";
    }
    cout<<endl;
    return 0;
}