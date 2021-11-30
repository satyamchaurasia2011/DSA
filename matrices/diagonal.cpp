#include<iostream>
using namespace std;

void set(int A[], int i, int j, int ele)
{
    if(i == j)
    {
        A[i] = ele;
    }
}
int main()
{
    int A[5],i,j;
    set(A, 0,0,2);
    set(A, 1,1,5);
    set(A, 2,2,6);
    set(A, 3,3,7);
    set(A, 4,4, 1);
    for(int k=0; k<5; k++)
    {
        for(int l=0; l<5; l++)
          {
              if(k == l)
                cout<<A[k]<<" ";
            else
              cout<<"0"<<" ";
          }
          cout<<endl;
    }
    
}