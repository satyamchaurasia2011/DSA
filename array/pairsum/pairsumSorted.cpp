#include<iostream>
using namespace std;
//COMPLEXITY  O(N)
int main()
{
   int n;
    cin>>n;
    int A[n];
    int k;
    cout<<"Enter element which equal to sum of pair in array ";
    cin>>k;
    for(int i=0; i<n; i++)  //Sorted  
      cin>>A[i];
    int i=0, j=n-1;
    while(i<j)
    {
        if(A[i] + A[j] == k){
           cout<<"( "<<A[i]<<" , "<<A[j]<<" )"<<endl;
           i++;
           j--;
        }
        else if(A[i] + A[j] > k)
         j--;
        else 
          i++;
    }
    return 0;
}