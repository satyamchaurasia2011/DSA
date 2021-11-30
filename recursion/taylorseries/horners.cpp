#include<iostream>
using namespace std;

////// USING  LOOP ///////////

// double e(double x, double n)  
// {
//     double s=1;
//     for( ; n>0; n--)
//     {
//         s = 1 + (x/n)*s;
//     }
//     return s;
// }

//USING  RECURSION ////
double e(double x, double n)
{
    static double s=1;
    if(n==0)
      return s;
    s = 1 + (x/n)*s;
    return e(x,n-1);
}
double sin(double x, double n)
{
  double s=1;
  for( ;n>=0; n -= 2)
  {
    s = 1 - ((x*x)/((n+2)*(n+3)))*s;
  }
  return x*s;
}
double cos(double x, double n)
{
  double s=1;
  for( ; n>=0; n -= 2)
    s = 1 - ((x*x)/((n+1)*(n+2)))*s;
  return s;
}
int main()
{
    double x,n;
    cin>>x>>n;
    cout<<e(x,n)<<endl;
    cout<<sin(x,n)<<endl;
    cout<<cos(x,n)<<endl;
    return 0; 
}