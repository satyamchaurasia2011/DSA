// #include<iostream>
// #include<string>

// using namespace std;
// class Stack
// {
//     public:
//         int top;
//         int size;
//         char *stk;
//         Stack():top{-1},size{5},stk{new char[100]}{}
//         void push(char x);
//         char pop();
//         void peek(int pos);
//     void display()
//     {
//         for(int i=top; i>-1; i--)
//            cout<<stk[i]<<endl;
//     }
// };

// void Stack::push(char x)
// {
//     if(top == size-1)
//       cout<<"Stack Overflow\n";
//     else{
//         top++;
//         stk[top] = x;
//     }
// }

// char Stack::pop()
// {
//     if(top == -1)
//       return 1;
//     else{
//         char x = stk[top];
//         top--;
//         return x;
//     }
// }

// void Stack::peek(int pos)
// {
//     if(top>top-pos+1)
//         cout<<"Unreachable\n";
//     else
//     {
//         cout<<"ele in "<<pos<<"position is "<<stk[top-pos+1]<<endl;
//     }
// }
// int isOperand(char c)
// {
//     if(c == '+' || c=='-'||c=='*' || c== '/'|| c=='(' || c==')' )
//        return 0;
//     else  
//       return 1;
// }

// int pref(char c)
// {
//     if(c == '*' || c=='/')
//       return 3;
//     else if(c == '+' || c=='-')
//        return 2;
//     else
//       return 1;
// }

// int main()
// {
//     Stack stak;
//     string infix,postfix;
//     cout<<"Enter infix notation \n";
//     cin>>infix;
//     int i,j;
//     i=0;
//     while(infix.length()>i)
//     {
//         if(infix[i] == ')')
//         {
//             while(stak.stk[stak.top] !='(')
//             {
//                 postfix +=  stak.pop();;
               
//             }
//             i++;
//         }
//         else if(isOperand(infix[i]))
//             postfix  += infix[i++];
//         else
//          {
//              if(pref(infix[i])>pref(stak.stk[stak.top]))
//                  stak.push(infix[i++]);
//              else
//              {
//                  postfix +=  stak.pop();;
                
//              }
//          }
//     }
//     while(stak.top!=-1)
//     {
//         postfix +=  stak.pop();
       
//     }
//     cout<<"Postfix operation is  "<<postfix<<endl;
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
 
//Function to return precedence of operators
int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/')
        return 2;
    else if(c=='*')
         return 1;
    else if(c == '+' || c == '-')
        return -1;
    else
        return -2;
}
 
// The main function to convert infix expression
//to postfix expression
void infixToPostfix(string s) {
 
    stack<char> st; //For stack operations, we are using C++ built in stack
    string result;
 
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        // If the scanned character is
        // an operand, add it to output string.
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if(c == '(')
            st.push('(');
 
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(c == ')') {
            while(st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
 
        //If an operator is scanned
        else {
            while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop(); 
            }
            st.push(c);
        }
    }
 
    // Pop all the remaining elements from the stack
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    cout << result << endl;
}
int main() {
    string exp = "((a+b)*c)-d^e^f";
    infixToPostfix(exp);
    return 0;
}
