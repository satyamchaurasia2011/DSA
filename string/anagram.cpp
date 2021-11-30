#include<iostream>

using namespace std;

int main()
{
    char A[] = "rrange";
    char B[] = "angerr";
    int i,h[26] = {0};
    for(i=0; A[i]!='\0'; i++)
     h[A[i]-97]++; 
    for(i=0; B[i]!='\0'; i++)
        h[B[i]-97]--;
    for(i=0; B[i]!='\0'; i++)
    {
        if(h[B[i]-97]<0 || h[B[i]-97]>0)
         { cout<<"Not an Anagram"<<endl;
          break;}
    }
    if(B[i] == '\0')
      cout<<"Anagram"<<endl;



    return  0;

}