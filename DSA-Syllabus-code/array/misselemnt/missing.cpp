#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n],sum=0;
    for(int i=0; i<n; i++)
      cin>>A[i];
    // for(int i=0; i<n; i++) // there is only one number is missing in sorted array
    // {
    //     if(A[i]-i != A[0]){
    //       cout<<A[0]+i<<" is missing\n";
    //      break;
    //     }
    // }
    
    //when there is more than one number is missing
    // int diff=A[0];
    // for(int i=0; i<n; i++)
    // {
    //     if(A[i]-i != diff)
    //     {
    //          while(diff<A[i]-i)
    //          {
    //              cout<<diff+i<<" is missing\n";
    //              diff++;
    //          }
    //     }
    // }
    //finding missing element in unsorted array
    int max = A[0];
    for(int i=0; i<n; i++)
    {
      if(max<A[i])
        max = A[i];
    }
    int B[max+1] = {0};
    for(int i=0; i<n; i++)
    {
      B[A[i]]++;
    }
    cout<<"Missing element is ";
    for(int i=1; i<=max; i++)
    {
      if(B[i] == 0)
        cout<<i<<" ";
    }
    cout<<endl;

    
    return 0;
}