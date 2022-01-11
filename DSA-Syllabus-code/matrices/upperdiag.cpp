#include<iostream>
using namespace std;

int main()
{
    int A[15];//Row major
    // for(int i=0; i<15; i++)
    //   cin>>A[i];

    // for(int i=0; i<5; i++)
    // {
    //     for(int j=0; j<5; j++)
    //     {
    //         if(i<=j)
    //         {
    //             cout<<A[(i)*5-((i-1)*(i))/2+(j-i)]<<" ";
    //         }
    //         else
    //           cout<<"0"<<" ";
    //     }
    //     cout<<endl;
    // }

    //Column major
    for(int i=0; i<15; i++)
       cin>>A[i];
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=5; j++)
        {
            if(i<=j)
            {
                cout<<A[(j*(j-1))/2+(i-1)]<<" ";
            }
            else
             cout<<"0"<<" ";
        }
        cout<<endl;
    }
}