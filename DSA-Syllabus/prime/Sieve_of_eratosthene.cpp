#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter value of n to generate prime numbers less than n ";
    cin>>n;
    bool A[n];
    if(n<=1)
      cout<<"-1"<<endl;
    for(int i=2; i<n; i++)  
      A[i] = true;
    for(int i=2; i<n; i++)  /////////////////complexity - O(nlog(logn))
    {
        if(A[i]){
            for(int j=2*i; j<n; j += i)
                 A[j] = false;
        }
        
    }
    cout<<"prime numbers are - ";
    for(int i=2; i<n; i++)
      (A[i] && cout<<i<<" ");
    return 0;
}