#include <iostream>
#include <stack>
using namespace std;

int prec(char opr)
{
    if (opr=='+' || opr=='-')
    {
        return 1;
    }
    else if (opr=='*' || opr=='/')
    {
        return 2;
    }
    else if (opr=='^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

string InfixToPostfix(string exp)
{
    stack <char> s;
    string result;

    for (int i=0; i<exp.length(); i++)
    {
        char c= exp[i];

        if ((c>='a'&& c<='z')||(c>='A'&& c<='Z')||(c>='0'&& c<='9') )
        {
            result +=c;
        }
        else if(c=='(')
        {
            s.push(c);
        }
        else if (c==')')
        {
            while (s.top()!='(')
            {
                result+=s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && (prec(c)<= prec(s.top())))
            {
                result+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        result+=s.top();
        s.pop();
    }
    return result;
}


string reverse(string exp)
{
    string reversed= "";
    for (int i= exp.length()-1; i>=0; i--)
    {
        reversed+= exp[i];
    }
    return reversed;
}

string InfixToPrefix(string exp)
{
    string revExp= reverse(exp);

    for (int i=0; i< revExp.length(); i++)
    {
        char c= revExp[i];

        if (c=='(')
        {
            c=')';
        }
        else if (c==')')
        {
            c=')';
        }
    }

    string prefix = InfixToPostfix(exp); 
    string revPre= reverse(prefix);
    return revPre; 
}


int main()
{
    string exp = ("5*(6+2)-8/4"); 
    cout << InfixToPrefix(exp);
    
    return 0;
}