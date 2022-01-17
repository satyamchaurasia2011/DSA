#include<iostream>
using namespace std;

int main()
{
    int n,temp;
    cout<<"Enter size of an array ";
    cin>>n;
    int A[n];
    cout<<"Enter elements ";
    for(int i=0; i<n; i++)
      cin>>A[i];
    for(int i=1; i<n; i++)
    {
        for(int j=i; j>=1; j--)
            if(A[j]<=A[j-1])
              {
                  temp = A[j];
                  A[j] = A[j-1];
                  A[j-1] = temp;
                 
              }
    }
    cout<<"Sorting using insertion is ";
    for(int i=0; i<n; i++)
      cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}