#include<iostream>
using namespace std;
// void Perm(char c[], int k)
// {
//     static char A[10];
//     static int temp[10] = {0};
//     int i;
//     if(c[k]=='\0')
//     {    A[k] = '\0';
//          cout<<A<<endl;
//     }
//     else {
//         for(int i=0; c[i]!='\0'; i++)
//         {
//             if(temp[i]==0)
//             {
//                 A[k] = c[i];
//                 temp[i] = 1;
//                 Perm(c, k+1);
//                 temp[i]=0;
//             }
//         }
//     }
// }

//ALTERNATE
void Perm(char s[], int l, int h)
{
    int i;
    if(l == h)
        cout<<s<<endl;
    else
    {
        for(i = l; i<=h; i++)
        {
            swap(s[i], s[l]);
            Perm(s, l+1, h);
            swap(s[i], s[l]);
        }
    }
}
void swap(char a, char b)
{
    char t;
    t = a;
    a = b;
    b= t;
}

int main()
{
    char s[] = "ABC";
    Perm(s,0,2);
}