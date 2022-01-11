#include<iostream>

using namespace std;

void insertion(int ht[], int key, int size)
{
    int ind = key % size;
    int i=1;
    while(ht[ind] != -1)
    {
        ind = (ind + i)%size;  //IN QUADRATIC PROBING (ind+i*i)%size // IN DOUBLE HASHING (ind + i*(prime no. less than size - (key*prime no. less than size)))%size
        i++;
    }
    ht[ind] = key;
}

bool search(int ht[], int key, int size)
{
     int ind = key % size;
    int i=1;
    while(ht[ind] != -1)
    {
        if(ht[ind] == key)
          return true;
        ind = (ind + i)%size;     //IN QUADRATIC PROBING (ind+i*i)%size  //IN DOUBLE HASHING (ind + i*(prime no. less than size - (key*prime no. less than size)))%size
        i++;
    }
    return false;
}
void display(int ht[], int size)
{
    for(int i=0; i<size; i++)
      cout<<ht[i]<<" ";
    cout<<endl;
}

int main()
{
    int A[] = {26, 30, 45, 23, 43, 74, 19, 29};
    int *k;
    k = new int[16];
    for (int i = 0; i < 16; i++)
        k[i] = -1;
    
    for(int i=0; i<8; i++)
      insertion(k, A[i], 16);
    display(k,16);
    cout<<"Enter a key to search ";
    int key;
    cin>>key;
    search(k, key, 16)?cout<<key<<" element is found" : cout<<"not found";
    return 0;
}