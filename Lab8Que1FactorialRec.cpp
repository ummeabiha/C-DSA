#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*factorial(n-1);
}


int main()
{
    int num;
    cout << "Enter the number to calculate its factorial" << endl;
    cin >> num;
    cout << "The factorial of " << num << " is " << factorial(num);

    return 0;
}