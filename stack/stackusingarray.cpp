#include<iostream>
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
    s.push('a');
    s.push('b');
    s.push('c');
   s.push('f');
   s.push('l');
    s.display();
     s.peek(9);
    s.pop();
     s.display();
    return 0;
}