#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
   int  temp = *x;
    *x = *y;
    *y = temp;
}

int partitioning(int A[], int l, int h)
{
    int pivot = A[l],temp;
    int i=l, j=h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j)
          swap(&A[i], &A[j]);
    }while(i<j);
    swap(&A[l], &A[j]);
    return j;
}

void quicksort(int A[], int l, int h)
{
    int j;
    if(l<h){
         j = partitioning(A, l, h);
        quicksort(A,l,j);
        quicksort(A,j+1,h);
    }
}

int main()
{
    int n;
    cout<<"Enter size of an array ";
    cin>>n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin>>A[i];
    A[n] = INT32_MAX;
    quicksort(A,0,n);
    for (int i = 0; i < n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}