#include<iostream>
using namespace std;
class Array
{
  int *A;
  int length;
  public:
    Array(int *a,int l)
    {
      A = a;
      length = l;
    }
    void Add(int x);
    void insert(int ind, int x);
    void del(int ind);
    int Bsearch(int l, int h, int ele);
    int get(int ind);
    void set(int ind, int ele);
    void merge(Array &arr, Array &arr1);
    void display();
   
    
};
void Array :: Add(int x)
{
  A[length] = x;
  length++;
}

void Array :: insert(int ind, int x)
{
  for(int i=length; i>ind; i--)
     A[i] = A[i-1];
  A[ind] = x;
  length++;
   
}

void Array :: del(int ind)
{
  for(int i=ind; i<length; i++)
      A[i] = A[i+1];
  length--;
}

int Array :: Bsearch(int l, int h, int ele)
{
  int mid;
 while(l<=h)
 {
   mid = (l+h)/2;
   if(A[mid] == ele){
     cout<<"Element found at";
     return mid+1;
   }
   else if(ele<A[mid])
     h = mid-1;
    else 
      l = mid+1;
 }
  cout<<"Element not found";
  return -1;
}

int Array :: get(int ind)
{
  if(ind>=0&&ind<length)
  return A[ind];
}

void Array :: set(int ind, int ele)
{
  if(ind>=0&&ind<length)
     A[ind] = ele;
}

void Array :: merge(Array &arr, Array &arr1)
{
  int i=0,j=0,k=0;
  while(i<arr.length && j<arr1.length)
  {
    if(arr.A[i]<arr1.A[j])
       i++;
    else if(arr.A[i] == arr1.A[j]){
      A[k++] = arr1.A[j++];
      i++;
    }
    else 
       j++;
  }
 
     length = k;
}

void Array :: display()
    {
      for(int i=0; i<length; i++)
        cout<<A[i]<<" ";
      cout<<endl;
    }
  
int main()
{
    int *A,*B,*C;
    A = new int[20];
    B = new int[20];
    C = new int[20];
    Array arr(A,5),arr1(B,5),arr2(C,10);
    for(int i=0; i<5; i++)
      cin>>A[i];
    for(int i=0; i<5; i++)
      cin>>B[i];
      arr2.merge(arr,arr1);
    arr2.display();

    
   
    return 0;
}