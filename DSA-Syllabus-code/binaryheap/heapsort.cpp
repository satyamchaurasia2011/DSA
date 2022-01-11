#include<iostream>
using namespace std;

void insert(int A[], int n)
{
    int i=n,temp;
    temp = A[n];
    while(i>0 && temp>A[(i-1)/2])
    {
        A[i] = A[(i-1)/2];
        i = (i-1)/2;
    }
    A[i] = temp;
}

void heapsort(int A[], int n)
{
    int x = A[0],i=0,temp;
    int j = 2*i+1;
    A[i] = A[n];
     while(j<=n-1)
    {
        if(A[j]<A[j+1])
           j = j+1;

         if(A[i] < A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i=j;
                j=2*j+1;
            }  
            else
              break; 
          
    }
    A[n] = x;
}

int main()
{
    int A[] = {10,20,30,25,40,35,5};
    for(int i=1; i<7; i++)
    {
        insert(A,i);
    }
    cout<<"Heap tree is - ";
    for(int i=0; i<7; i++)
      cout<<A[i]<<" ";
    cout<<"\n sorted - \n";
     for(int i=6; i>=1; i-- )
        heapsort(A,i);
     for(int i=0; i<7; i++)
         cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}