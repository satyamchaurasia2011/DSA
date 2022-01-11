#include<iostream>
using namespace std;
void TOH(int n, int a, int b, int c)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        cout<<a<<","<<c<<endl;
        TOH(n-1,b,a,c);
    }
}
int main()
{
    int n,a=1,b=2,c=3;
    cout<<"Enter no. of rings ";
    cin>>n;
    TOH(n,a,b,c);
    return 0;
}