#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==0)
      return 1;
    else 
     return fact(n-1) * n;
}
int main()
{
    int n;
    cout<<"Enter number for factorial - ";
    cin>>n;
    cout<<fact(n)<<endl;
}