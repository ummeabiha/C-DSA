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

void InfixToPostfix(string exp)
{
    stack<char> s;
    string result;

    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            s.push(c);

        else if (c == ')')
        {
            while (s.top() != '(')
            {
                result += s.top();
                s.pop();
            }
            s.pop();
        }

        else
        {
            // pop the elements from stack which has same or higher precedence
            while (!s.empty() && (prec(c) <= prec(s.top())))
            {
                result += s.top();
                s.pop();
            }
            s.push(c); // push the current operator in stack
        }
    }

    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }

    cout << result << endl;
}


int main()
{
    string exp = "(A+(B*C-(D/E^F)*G)*H)";
    InfixToPostfix(exp);
    
    return 0;
}