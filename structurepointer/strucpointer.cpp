#include<iostream>
using namespace std;
struct point
{
    int A[5];
    int l;
};
void func(struct point *p1)
{
    p1->A[0] = 2;
}
int main()
{
    struct point p{{3,2,1,4},10};
    func(&p); 
    cout<<p.A[0]<<endl<<p.A[1]<<endl;
    return 0;
}