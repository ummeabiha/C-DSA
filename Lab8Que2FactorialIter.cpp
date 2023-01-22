#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
        int fact=1;
        for (int k=1; k<=n; k++)
        {
            fact= fact*k;
        }
        return fact;
    }
}

int main()
{
    int num;
    cout << "Enter the element: " << endl;
    cin >> num;
    cout << factorial(num);
    
    return 0;
}