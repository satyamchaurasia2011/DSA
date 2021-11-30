#include<iostream>
using namespace std;

 int main()
 {
     int n,temp,swap;
     cout<<"Length of an number\n";
     cin>>n;
     int A[n];
     for(int i=0; i<n; i++)
       cin>>A[i];
     for(int i=0; i<n-1; i++)
     {
         temp=i;
         for(int j=i; j<n; j++)
         {
             if(A[j]<A[temp])
               temp = j;
         }
        swap = A[i];
        A[i] = A[temp];
        A[temp] = swap;

     }
    cout<<"By using Selection Sort Sorted element are - ";
    for(int i=0; i<n; i++)
      cout<<A[i]<<" ";
    cout<<endl;
    return 0;
 }