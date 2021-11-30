#include<iostream>
using namespace std;
int a = 0; //Global variable.
int fun1(int n)  //Tail recursion.
{
    //static int a = 0; //static variable.
    if(n>0)
    {
        a++;
        return fun1(n-1)+a;
    }
    return 0;
}
int main()
{
    int x=5;
    cout<<fun1(x)<<endl;
    return 0;
}