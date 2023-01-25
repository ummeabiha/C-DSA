#include <iostream>
using namespace std;

const int maxsize= 4;

class Stack
{
    public:
    int top, pop, stack[maxsize];

    Stack()
    {top=-1;}

    void Push(int item)
    {
        if (top<maxsize)
        {
            top++;
            stack[top]= item;
            cout << item << endl;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    int Pop()
    {
        if(top==-1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            pop= stack[top];
            top--;
            return pop;
        }
    }

    int IsEmpty()
    {
        if (top==-1)
        {
            return -1;
        }

        else
        {
            return 0;
        }
    }
};

int main()
{
    Stack s; 
    cout <<"Elements in a Stack:"<< endl; 
    s.Push(80); 
    s.Push(70); 
    s.Push(60); 
    s.Push(67); 
    s.Push(77); 
    s.Push(33); 
    
    cout<<"\nPopped Elements Are:"<<endl; 
    
    while(!s.IsEmpty())
    {
        cout << s.Pop() << endl;
    }
    s.Pop();

    return 0;
}