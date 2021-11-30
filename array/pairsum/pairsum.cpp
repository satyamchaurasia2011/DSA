#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n];
    int k;
    cout<<"Enter element which equal to sum of pair in array ";
    cin>>k;
    for(int i=0; i<n; i++)
      cin>>A[i];
      // COMPLEXITY  O(N^2)  //UNSORTED
    // for (int i = 0; i < n-1; i++)
    // {
    //     for(int j=i+1; j<n; j++)
    //     {
    //         if(A[i] + A[j] == k)
    //           cout<<"( "<<A[i]<<" , "<<A[j]<<" )"<<endl;
    //     }
    // }

    // USING HASH TABLE O(N) --
    int max = A[0];
    for(int i=1; i<n; i++)
      if(max<A[i])
        max = A[i];
    int B[max+1]={0};
    for(int i=0; i<n; i++)
    {
      if(B[k-A[i]] != 0 && k-A[i] >=0 )
      {
        cout<<"( "<<A[i]<<" , "<<k-A[i]<<" )"<<endl;
      }
      B[A[i]]++;
    }
    return 0;
    
}