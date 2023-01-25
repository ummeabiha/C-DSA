#include <iostream>
#include <stack>
using namespace std;

const int maxsize= 2;

class Stack
{
    public:
    int top=-1, pop, stack[maxsize];

    void Push(int item)
    {
        if (top>=maxsize)
        {
            cout << "Stack Overflow." << endl;
        }
        else
        {
            top++;
            stack[top]=item;
            cout << item << " ";
        }
    }

    int Pop()
    {
        if(top==-1)
        {
            cout << "Stack Underflow." << endl;
        }
        else
        {
            int pop= stack[top];
            top--;
            return pop;
        }
    }

    bool IsEmpty()
    {
        if (top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    Stack s;
    s.Push(14);
    s.Push(12);
    s.Push(16);
    s.Push(18);

    while (!s.IsEmpty())
    {
        int pop= s.Pop();
        cout << pop << " ";
    }
    s.Pop();

    return 0;
}