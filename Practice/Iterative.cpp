#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact=1;
    for (int i=1; i<=n; i++)
    {
        fact*= i;
    }
    return fact;
}

void fibonacci(int n)
{
    int prevNum=1, currentNum=1, prevprevNum=0;
    cout << "Term 1: " << prevNum << endl;
    cout << "Term 2: " << currentNum << endl;

    for (int i=3; i<=n; i++)
    {
        prevprevNum= prevNum;
        prevNum= currentNum;
        currentNum= prevNum+prevprevNum;
        cout << "Term " << i << ": " << currentNum << endl;
    }
}


int main()
{
    int n=5;
    cout << n << "! =" << factorial(n) << endl;
    cout << "Fibonacci Series of " << n << " terms is: " << endl;
    fibonacci(n);

    return 0;
}