#include<iostream>
using namespace std;

bool isvalid(char *name)
{
    for(int i=0; name[i] != '\0'; i++)
    {
        if(!(name[i]>=65&&name[i]<=90) && !(name[i]>=97&&name[i]<=122) && !(name[i]>=48&&name[i]<=57))
           return false;
    }
    return true;
}

int main()
{
    char *name = "Abcq234";
    if(isvalid(name))
      cout<<"Valid"<<endl;
    else 
      cout<<"Invalid"<<endl;
}