#include<iostream>
#include<stack>
using namespace std;

int isOperand(char c)
{
    if(c == '+' || c=='-' || c=='*' || c=='/')
        return 0;
    else
      return 1;
}
int evaluation(string exp)
{
    stack<int>stk;
    int i=0,a,b,res;
    while(exp.length()>i)
    {
        if(isOperand(exp[i]))
           stk.push(exp[i++]-'0');
        else
          {
              b= stk.top();
              stk.pop();
              a = stk.top();
              stk.pop();
              switch(exp[i])
              {
                  case '+' : res = a+b;
                            stk.push(res);
                            break;
                  case '-' : res = a-b;
                            stk.push(res);
                            break;
                  case '*' : res = a*b;
                             stk.push(res);
                             break;
                  case '/' : res = a/b;
                             stk.push(res);
                             break;
              }
              i++;
          }
    }
    res = stk.top();
    stk.pop();
    return res;
}

int main()
{
    string exp = "35*62/+4-";
    cout<<evaluation(exp)<<endl;
    return 0;
    
}