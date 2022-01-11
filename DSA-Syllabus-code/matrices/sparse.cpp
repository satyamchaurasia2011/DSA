#include<iostream>
using namespace std;

// int main()
// {
//     int sp[5][5],spa[7][3],n;
//     spa[0][0] = 5;
//     spa[0][1] = 5;
//     cout<<"Enter number of non-zero element ";
//     cin>>n;
//     if(n>(5*5)/4)
//     {
//         cout<<"not a sparse matrix";
//     }
//     else{
//         spa[0][2] = n;
//         cout<<"enter row no., column no. and element ";
//         int k=1;
//         for(int i=1; i<=n; i++)
//         {
//             cin>>spa[i][0]>>spa[i][1]>>spa[i][2];
//         }
//         for(int i=0; i<5; i++)
//         {
//             for(int j=0; j<5; j++)
//             {
//                 if(spa[k][0]==i && spa[k][1]==j)
//                 {
//                     cout<<spa[k++][2]<<" ";
//                 }
//                 else
//                  cout<<"0 ";
//             }
//             cout<<endl;
//         }
//     }
// }

class Element
{
    public:
        int i;
        int j;
        int x;
};

class Sparse
{
    int m,n,num;
    Element *ele;
    public:
        Sparse(int m, int n, int num)
        {
            this->m = m;
            this->n = n;
            this->num = num;
            ele = new Element[this->num];
        }
        Sparse operator + (Sparse &s);
        friend  istream & operator >> (istream &is, Sparse &s);
        friend ostream & operator << (ostream &os, Sparse &s);
};

Sparse Sparse :: operator +(Sparse &s)
{
    int i,j,k;
    if(m != s.m || n != s.n)
       return Sparse(0,0,0);
    Sparse *sum = new Sparse(m,n,num+s.num);
    i=j=k=0;
    while(i<num && j<s.num)
    {
        if(ele[i].i < s.ele[j].i)
           sum->ele[k++] = ele[i++];
        else if(ele[i].i > s.ele[j].i)
            sum->ele[k++] = ele[j++];
        else{
            if(ele[i].j < s.ele[j].j)
              sum->ele[k++] = ele[i++];
            else if(ele[i].j > s.ele[j].j)
                sum->ele[k++] = ele[j++];
            else{
            sum->ele[k] = ele[i];
            sum->ele[k++].x = ele[i++].x+ele[j++].x;
          }
        }
    }
    for( ; i<num; i++)
      sum->ele[k++] = ele[i];
    for( ; j<s.num; j++)
      sum->ele[k++] = ele[j];
    return *sum;
}

istream & operator>>(istream &is, Sparse &s)
{
    cout<<"Enter non-zero elements";
    for(int i=0; i<s.num; i++)
        cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
    return is;
}

ostream & operator<<(ostream &os, Sparse &s)
{
    int k=0;
    for(int i=0; i<s.m; i++)
    {
        for(int j=0; j<s.n; j++)
        {
            if(s.ele[k].i == i && s.ele[k].j == j)
               cout<<s.ele[k++].x<<" ";
            else 
              cout<<"0 ";
        }
        cout<<endl;
    }
    return os;
}

int main()
{
    Sparse s1(5,5,5);
    Sparse s2(5,5,5);
    cin>>s1;
    cin>>s2;
    Sparse sum = s1+s2;
    cout<<"First Sparse matrix is - "<<endl<<s1;
    cout<<"Second Sparse matrix is - "<<endl<<s2;
    cout<<"Sum is - "<<endl<<sum;
}