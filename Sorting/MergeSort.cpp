#include<iostream>
using namespace std;

//ITERATIVE METHOD ---
void merge(int A[], int l, int mid, int h)
{
    int i=l;
    int j = mid+1;
    int k=l;
    int B[100];
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
          B[k++] = A[i++];
        else
          B[k++] = A[j++];
    }
    for( ; i<=mid; i++)
      B[k++] = A[i];
    for( ; j<=h; j++)
      B[k++] = A[j];
    for(int i=l; i<=h; i++)
      A[i] = B[i];
}
//RECURSIVE  METHOD/////////////
void mergeSort(int A[], int l, int h)
{
  if(l<h)
  {
    int mid = (l+h)/2;
    mergeSort(A,l,mid);
    mergeSort(A,mid+1,h);
    merge(A,l,mid,h);
  }
}


int main()
{
     int p,i,l,mid,h,n;
     cout<<"Enter size of an array";
     cin>>n;
     int A[n];
     for(int i=0; i<n; i++)
       cin>>A[i];
       //iterative
    //  for(p=2; p<=n; p=p*2)
    //  {
    //      for(i=0; i+p-1<=n; i=i+p)
    //      {
    //          l = i;
    //          h = i+p-1;
    //          mid = (l+h)/2;
    //          merge(A,l,mid,h);
    //      }
    //  }
    //  if(p/2<n)
    //    merge(A,0,p/2,n-1);
  mergeSort(A,0,n-1);
    for(int i=0; i<n; i++)
       cout<<A[i]<<" ";
    return 0;
}


