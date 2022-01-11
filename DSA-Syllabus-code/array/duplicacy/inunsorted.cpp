#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n],count;
    for (int i = 0; i < n; i++)
        cin>>A[i];

    //COMPLEXITY - N^2
    // for (int i = 0; i < n-1; i++)
    // {
    //     count=1;
    //     if(A[i] != -1)
    //     {
    //         for(int j=i+1; j<n; j++)
    //         {
    //             if(A[i] == A[j])
    //             {
    //                 A[j] = -1;
    //                 count++;
    //             }
    //         }
    //         if(count>1)
    //         cout<<"duplicate element is "<<A[i]<<" occurs "<<count<<" times."<<endl;
    //     }
    // }

    // HASH METHOD ---COMPLEXITY O(N)/////////////

    int max = A[0];
    for(int i=1; i<n; i++)
    {
        if(A[i]>max)
          max = A[i];
    }
    int B[max+1] = {0};
    for(int i=0; i<n; i++)
        B[A[i]]++;
    for (int i = 0; i <= max; i++)
    {
        if(B[i]>1)
          cout<<"duplicate element is "<<i<<" occurs "<<B[i]<<" times."<<endl;
    }
    
    
    return 0;
    
}