#include<iostream>
#include<vector>
#include<list> 

using namespace std;



void insertion(list<int>h[], int key, int bucket_size)
{
    int ind = key%bucket_size;
    h[ind].push_back(key);
}

void deletion(list<int>h[], int key, int bucket_size)
{
     int ind = key%bucket_size;
    list <int> :: iterator i;
    for(i=h[ind].begin(); i!=h[ind].end(); i++)
      if(*i == key)
        break;
    if(i != h[ind].end())
        h[ind].erase(i);
}

void display(list<int>h[], int bucket_size)
{
    for(int i=0; i<bucket_size; i++)
    {
        cout<<i;
        for(auto x : h[i])
           cout<<"-->"<<x;
        cout<<endl;
    }
}

int main()
{
    int bucket = 10;
    list<int> *hash_table;
    int a[] = {13, 22, 43, 28, 19};
    hash_table = new list<int>[bucket];
    for(int i=0; i<5; i++)
     insertion(hash_table, a[i],bucket);
    display(hash_table, bucket);
    deletion(hash_table, 43, bucket);
    display(hash_table, bucket);
    return 0; 

}