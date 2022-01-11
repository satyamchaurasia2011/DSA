#include<iostream>
using namespace std;
//  RECURSION METHOD  TIME & SPACE - O(N)
// int sum(int n)
// {
//     if(n==0)
//        return 0;
//     else 
//        return sum(n-1)+n;
     
// }
// int main()
// {
//     int n;
//     cout<<"no. of natural number\n";
//     cin>>n;
//     cout<<sum(n);
//     return 0;
// }

//SIMPLE  TIME & SPACE COMPLEX - O(1)
int  main()
{
    int n;
    cout<<"Enter no. of natural number\n";
    cin>>n;
    cout<<(n*(n+1))/2<<endl;
    return 0;
}