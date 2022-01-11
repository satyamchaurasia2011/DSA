#include<iostream>
using namespace std;
// int fact(int n)
// {
//     if(n<=1)
//       return 1;
//     return fact(n-1)*n;
// }
// int C(int n, int r)
// {
//     int t1,t2,t3;
//     t1 = fact(n);
//     t2 = fact(r);
//     t3 = fact(n-r);
//     return t1/(t2*t3);
// }

//By Pascal's Triangle-
int C(int n, int r)
{
    if(r == 0 || r == n)
      return 1;
    else
      return C(n-1,r-1)+C(n-1,r);
}
int main()
{
    int n,r;
    cin>>n>>r;
    cout<<n<<"C"<<r<<" = "<<C(n,r)<<endl;
}