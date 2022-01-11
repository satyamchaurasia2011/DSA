#include<iostream>
using namespace std;
int fun(int n)
{
    if(n>100)
      return n-10;
    else
      return fun(fun(n+11)); //nested recursion call.
}
int main()
{
    int n = 109;
    cout<<fun(n)<<endl;
    return 0;
}