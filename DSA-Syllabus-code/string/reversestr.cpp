#include<iostream>
using namespace std;

int main()
{
    char s[] = "gaang";
    int len=0;
    for(int i=0; s[i] != '\0'; i++)
    {
        len++;
    }
    int i =0, j=len-1;
    // char temp;
    // while(i<j)
    // {
    //     temp = s[i];
    //     s[i] = s[j];
    //     s[j] = temp;
    //     i++;
    //     j--;
    // }

    //palindrome
    while(i<j)
    {
        if(s[i] != s[j])
        {
            cout<<"Not palindrome"<<endl;
            break; 
        }
        i++;
        j--;
    }
    if(i>=j)
      cout<<"Palindrome"<<endl;

    return 0;
}