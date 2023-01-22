#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n==1 || n==0)
    {
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

void display(int n)
{
    for(int i=0;i<n;i++)
    { 
        cout<< fibonacci(i)<<" "; 
    } 
}


int main()
{
    int n; 
    cout<<"Enter any term number of sequence:"<<endl; 
    cin>>n; 
    display(n);

    return 0; 
} 