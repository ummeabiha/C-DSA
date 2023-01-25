#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    stack <char> s1;
    stack <char> s2;
    string var;

    cout << "Enter the String:" << endl; 
    getline(cin, var);
    
    cout << "Input: ";
    for (int i=0; i<var.length(); i++)
    {
        s1.push(var[i]);
        cout << var[i];
    }

    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    cout << "\nOutput: ";
    while(!s2.empty())
    {
        cout << s2.top();
        s2.pop();
    }

    return 0;
}