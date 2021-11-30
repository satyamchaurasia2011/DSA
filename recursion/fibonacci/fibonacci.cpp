#include<iostream>
using namespace std;
//Recursive of O(2^n)
// int fib(int n)
// {
//     if(n<=1)
//       return n;
//     return fib(n-2)+fib(n-1);
    
// }

//Iterative Method O(n)
// int fib(int n)
// {
//     int f0=0,f1=1,s=0;
//     for(int i=2; i<=n; i++)
//     {
//         s = f0 + f1;
//         f0 = f1;
//         f1 = s;
//     }
//     return s;
// }

//Alternate way of recursion O(n)
 int F[10];
int fib(int n)
{
   if(n<=1)
    {
        F[n] = n;
        return n;     
    }
   else {
       if(F[n-2] == -1)
         F[n-2] = fib(n-2);
        if(F[n-1] == -1)
          F[n-1] = fib(n-1);
        return F[n-2]+F[n-1];
   }
}
int main()
{
    int n;
    cout<<"Enter no. of fibnocci terms : ";
    cin>>n;
    for(int i=0; i<10; i++)
      F[i] = -1;
    cout<<fib(n)<<endl;
    return 0;
}