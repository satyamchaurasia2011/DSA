#include<iostream>
using namespace std;

int max(int A[], int n)
{
    int max=A[0];
    for(int i=1; i<n; i++)
        if(max<A[i])
          max = A[i];
    return max;
}

void countsort(int A[], int n)
{
    int max_element;
    max_element = max(A,n);
    int *p = new int[max_element+1];
    for(int i=0; i<max_element+1; i++)
        p[i] = 0;
    for(int i=0; i<n; i++)
       p[A[i]]++;
    int i=0,j=0;
    while(i<max_element+1)
    {
        if(p[i]>0)
        {
            A[j++] = i;
            p[i]--; 
        }else
          i++;
    }
}

int main()
{
    int n;
    cout<<"Enter size of an array ";
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)
      cin>>A[i];
    countsort(A,n);
    cout<<"sorted - ";
    for (int i = 0; i < n; i++)
    {
       cout<<A[i]<<" ";
    }
    return 0;
}