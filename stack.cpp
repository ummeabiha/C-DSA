#include <iostream>
using namespace std;

void push(int top, int size, int item, int stack[])
{
    if (top >= (size-1))
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        stack[top]=item;
        cout << item << " is pushed into the stack" << endl;
    }
}

void search(int top, int stack[])
{
    if (top < 0) 
    {
        cout << "Stack is Empty";
    }
    else 
    {
        int x = stack[top];
        cout << x << endl;
    }
}

int main()
{
    int stack[3];
    int top=-1, size=3, item=0;

    for(int i=0; i<=size; i++)
    {
        cout << "Enter item " << endl;
        cin >> item;
        push(top,size,item,stack);
    }

    cout << "Stackkkk " << endl;
    search(top,stack);

    return 0;
}