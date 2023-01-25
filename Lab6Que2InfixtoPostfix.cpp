#include <iostream>
#include <stack>
using namespace std;

/*
ALGORITHM:
Push ( onto stack and add ) to the end of expression.
Scan Q from left to right until the stack is empty and repeat steps:
    a- If an operand occurs, add it to P.
    b- If an operator occurs, then:
        1- Repeatedly pop from stack and add to P each operator(on top of stack)
           which has same or higher precedence.
        2- Add operator to stack. 
    c- If ( occurs, push it to stack.
    d- If ) occurs then:
        1- Repeatedly pop from stack and add to P each operator(on top of stack)
           until left parenthesis occurs.
        2- Remove parenthesis.
*/


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
            s.push('(');

        
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
            //pop the elements from stack which has same or higher precedence
            while (!s.empty() && prec(c) <= prec(s.top())) 
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