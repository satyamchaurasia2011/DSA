#include<iostream>
using namespace std;
void fun(int a) //head recursion...
{
    if(a>0)
    {
        fun(a-1);
        cout<<a<<" ";
        
    }
}
int main()
{
    int x=3;
    fun(3);
    return 0;
}