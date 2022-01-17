#include<iostream>
#include<string>
using namespace std;
template<class T>
class Stack
{
    public:
        int top;
        int size;
        T *stk;
        Stack():top{-1},size{5},stk{new T[size]}{}
        void push(T x);
        void pop();
        void peek(int pos);
    void display()
    {
        for(int i=top; i>-1; i--)
           cout<<stk[i]<<endl;
    }
};
template<class T>
void Stack<T>::push(T x)
{
    if(top == size-1)
      cout<<"Stack Overflow\n";
    else{
        top++;
        stk[top] = x;
    }
}
template<class T>
void Stack<T>::pop()
{
    if(top == -1)
      cout<<"Empty Stack\n";
    else{
        top--;
    }
}
template<class T>
void Stack<T>::peek(int pos)
{
    if(top>top-pos+1)
        cout<<"Unreachable\n";
    else
    {
        cout<<"ele in "<<pos<<"position is "<<stk[top-pos+1]<<endl;
    }
}
int main()
{
    Stack<char>s;
  string str;
  cout<<"Enter expression ";
  cin>>str;
  for(int i=0; i<str.length(); i++)
  {
      if(str[i] == '('||str[i]=='{'||str[i]=='[')
        s.push(str[i]);
      else if(str[i] == ')'||str[i]=='}'||str[i]==']')
      {
          if(s.top==-1){
                   cout<<"wrong expression";
                   exit(0);
          }
          
          if(str[i]<50)
          {
              if(s.stk[s.top] == str[i]-1)
                 s.pop();
          }
          else
          {
              if(s.stk[s.top] == str[i]-2)
                s.pop();
          }
      }
  }
  if(s.top==-1)
    cout<<"Right Expression";
  else
    cout<<"wrong expression";
    return 0;
}