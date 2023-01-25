#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Stack
{
public:
    stack<char> s;

    string reverse(string exp)
    {
        string reversed="";
        for (int i = exp.length() - 1; i >= 0; i--)
        {
            reversed+= exp[i];
        }
        return reversed;   
    }

    void OneStack(string exp)
    {
        string reversed= reverse(exp);

        for (int i = 0; i < reversed.length(); i++)
        {
            s.push(reversed[i]);
        }

        while (!s.empty())
        {
            cout << s.top() << "";
            s.pop();
        }
    }
};

int main()
{
    string exp;
    cout << "Enter a Expression: " << endl;
    getline(cin, exp);

    Stack s;
    s.OneStack(exp);

    return 0;
}