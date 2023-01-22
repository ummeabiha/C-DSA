#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack <char> s1;
    stack <char> s2;
    string var;

    cout << "Enter the String:" << endl; cin >> var;
    cout << "Input: ";

    // Pushing the variables in stack1
    for(int i=0; i<var.length(); i++)
    {
        cout << var[i];
        s1.push(var[i]);
    }

    // Popping the elements from stack1 and pushing in stack2
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    cout << "\nOutput: ";
    while (!s2.empty())
    {
        cout << s2.top();  //Printing the elements of stack2
        s2.pop();
    }
    return 0;
}