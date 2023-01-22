#include <iostream>
using namespace std;

int arr[5];
int n= sizeof(arr)/sizeof(arr[0]);
int topS1=-1;
int topS2= n;


void pushS1(int item, int arr[])
{
    if (topS1+1==topS2)
    {
        cout << "\nStack1 Overflow\n";
    }
    else
    {
        topS1++;
        arr[topS1]= item;
    }
}

void pushS2(int item, int arr[])
{
    if (topS1+1==topS2)
    {
        cout << "\nStack2 Overflow\n";
    }
    else
    {
        topS2--;
        arr[topS2]= item;
    }

}

int popS1()
{
    if (topS1==-1)
    {
        cout << "\nStack1 Underflow" << endl;
        return -1;
    }
    else
    {
        int pop1= arr[topS1];
        topS1--;
        return pop1;
    }
}

int popS2()
{
    if (topS2==n)
    {
        cout << "\nStack2 Underflow" << endl;
        return -1;
    }
    else
    {
        int pop2= arr[topS2];
        topS2++;
        return pop2;
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
    pushS1(22, arr); 
    pushS1(44, arr); 
    pushS1(66, arr); 
    pushS1(68, arr); 
    pushS1(65, arr); 
    
    traverse(arr, n); 
    pushS1(64, arr); 

    cout<<"\nthe popped element is "<<popS1()<<endl; 
    cout<<"the popped element is "<<popS1()<<endl; 

    return 0;
}