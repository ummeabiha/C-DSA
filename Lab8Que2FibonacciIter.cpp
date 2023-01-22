#include <iostream>
using namespace std;

void Fibonacci(int n)
{
    int prevNum=1, currNum=1, prevprevNum=0;
    cout << "Term 1: " << prevNum << endl;
    cout << "Term 2: " << currNum << endl;

    for(int i=3; i<=n; i++)
    {
        prevprevNum= prevNum;
        prevNum= currNum;
        currNum= prevprevNum+prevNum;
        cout << "Term " << i << ": " << currNum << endl;
    }
}

int main()
{
    int num;
    cout << "Enter the element: " << endl;
    cin >> num;
    Fibonacci(num);

    return 0;
}