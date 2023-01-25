#include <iostream>
using namespace std;

int arr[5];
int n = sizeof(arr) / sizeof(arr[0]);
int top1 = -1;
int top2 = n;

void Push1(int arr[], int item)
{
    if (top1 + 1 == top2)
    {
        cout << "Stack Overflow" << endl;
    }

    else
    {
        top1++;
        arr[top1] = item;
    }
}

void Push2(int arr[], int item)
{
    if (top1 + 1 == top2)
    {
        cout << "Stack Overflow" << endl;
    }

    else
    {
        top2--;
        arr[top2] = item;
    }
}

int Pop1()
{
    if (top1 == -1)
    {
        cout << "Stack Underflow" << endl;
    }

    else
    {
        int pop = arr[top1];
        top1--;
        return pop;
    }
}

int Pop2()
{
    if (top2 == n)
    {
        cout << "Stack Underflow" << endl;
    }

    else
    {
        int pop = arr[top2];
        top2++;
        return pop;
    }
}

void traverse(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    Push1(arr, 22);
    Push1(arr, 44);
    Push1(arr, 66);
    Push1(arr, 77);
    Push1(arr, 88);
    traverse(arr, n);
    Push1(arr, 66);

    cout << "\nthe popped element is " << Pop1() << endl;
    cout << "the popped element is " << Pop1() << endl;
    cout << "the popped element is " << Pop1() << endl;
    cout << "the popped element is " << Pop1() << endl;

    return 0;
}