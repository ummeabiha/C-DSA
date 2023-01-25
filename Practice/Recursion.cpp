#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n==0)
    {
        return 1;
    }
    return n*factorial (n-1);
}

int fibonacci(int n)
{
    if (n==0 || n==1)
    {
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

void display(int n)
{
    for (int i=0; i<n; i++)
    {
        cout << fibonacci(i) << " ";
    }
}

int main()
{
    int n=5;
    cout << n << "! = " << factorial(n) << endl;
    cout << "Fibonacci series is: " << " "; display(n);
    return 0;
}