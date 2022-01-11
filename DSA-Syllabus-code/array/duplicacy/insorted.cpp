#include<iostream>
using namespace std;
int main()
{
    int n,lastDuplicate=0;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++)
      cin>>A[i];
      //FINDING DUPLICATE ELEMENTS IN A LIST
    // cout<<"duplicate elements in a list - ";
    // for(int i=0; i<n-1; i++)
    // {
    //     if(A[i] == A[i+1] && A[i] != lastDuplicate){
    //         cout<<A[i]<<" ";
    //         lastDuplicate = A[i];
    //     }
    // }

    // COUNTING NUMBER OF APPEARANCE OF DUPLICATE NUMBERS
    // int i,j;
    // for( i=0; i<n-1; i++)
    // {
    //     if(A[i] == A[i+1])
    //     {
    //         j=i+1;
    //         while(A[i] == A[j])
    //             j++;
    //         cout<<"duplicate element is "<<A[i]<<" occurs "<<j-i<<" times"<<endl;
    //         i = j-1;
    //     }
    // }
    // cout<<endl;

    //USING HASH METHOD------   
    int B[A[n-1]+1] = {0};
    for(int i=0; i<n; i++)
    {
        B[A[i]]++;
    }
    for(int i=0; i<=A[n-1]; i++)
    {
        if(B[i]>1)
           cout<<"duplicate element is "<<i<<" occurs "<<B[i]<<" times"<<endl;
    }
    return 0;
}