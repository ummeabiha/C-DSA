#include <iostream>
#include<stack>
using namespace std;


int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string InfixToPostfix(string exp)
{
    stack<char> s;
    string result;

    for(int i=0; i<exp.length(); i++)
    {
        char c= exp[i];

        if ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        {
            result += c;
        }

        else if (c=='(')
        {
            s.push('(');
            s.pop();
        }

        else if (c==')')
        {
            while (s.top()!='(')
            {
                result+=c;
                s.pop();
            }
            s.pop();
        }
        else
        {
            //pop the elements from stack which has same or higher precedence
            while (!s.empty() && prec(c) <= prec(s.top())) 
            {
                result += s.top();
                s.pop();
            }
            s.push(c); // push the current operator in stack
        }

        while (!s.empty())
        {
            result += s.top();
            s.pop();
        }

        return result;
    }
}      


string InfixToPrefix(string exp) 
{ 
    reverse(exp.begin(), exp.end());

    for (int i = 0; i < exp.length(); i++) 
    { 
        char c= exp[i];
        
        if (c == '(') 
        { 
            c = ')'; 
        } 
        else if (c == ')') 
        { 
            c = '('; 
        } 
    } 
    string prefix = InfixToPostfix(exp); 
    reverse(prefix.begin(), prefix.end()); 
    return prefix; 
} 

int main() 
{ 
    string s = ("5*(6+2)-8/4"); 
    cout << InfixToPrefix(s) << endl; 
    return 0; 
} 



