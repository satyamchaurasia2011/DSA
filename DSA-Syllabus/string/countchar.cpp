#include<iostream>
using namespace std;

int main()
{
    char c[] = "finding";
    // int A[26] = {0};
    // for(int i=0; c[i] != '\0'; i++)
    // {
    //     A[c[i] - 97]++;
    // }
    // char ch;
    // for(int i=0; i<26; i++)
    //   if(A[i]>0){
    //      ch = i+97;
    //      cout<<ch<<" occurs "<<A[i]<<endl;
    //   }
      
      //USING BITS --
     int h=0,x,r;
     for(int i=0; c[i] != '\0'; i++)
     {
       x=1;
       r = c[i]-'a';
       x = x<<r;
       
       if((x&h )>0)
         cout<<c[i]<<" is duplicate"<<endl;
        else
         h = x|h;
     }

    return 0;
}