#include<iostream>

using namespace std;

int main()
{
    int n,temp;
    cout<<"Enter size";
    cin>>n;
    int A[n];
     cout<<"Enter elements - ";
     for(int i=0; i<n; i++)
      cin>>A[i];
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
            if(A[j]>A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
    }
    cout<<"Using Bubble Sort Sorted elements are - ";
    for(int i=0; i<n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}