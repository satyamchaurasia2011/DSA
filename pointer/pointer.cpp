#include<iostream>
using namespace std;
struct cuboid
{
    int l,b,h,area;
};

int main()
{
    struct cuboid *c = new cuboid[3];
    struct cuboid *(&d) = c; // reference
    for(int i=0; i<3; i++)
    {
        cout<<"Enter dimensions(l,b,h) of cuboid "<<i+1<<endl;
        cin>>(c+i)->l>>(c+i)->b>>(c+i)->h;
        (d+i)->area = (c+i)->l*(c+i)->b*(c+i)->h;
    }
    for (int i = 0; i < 3; i++)
    {
       cout<<"\narea of cuboid "<<i+1<<" is - "<<(d+i)->area<<endl;
    }
    

}