#include <iostream>
using namespace std;

void LinearSearch(int arr[], int size)
{
    int element, loc=0;
    cout<< "Enter the element you want to search in an array: " << endl;
    cin >> element;

    int n=size+1;
    arr[n]=element;

    while(arr[loc]!=element)
    {
        loc++;
    }
    if (loc==n) 
    { 
        cout << "Item not Found!" << endl; 
    } 
    else
    { 
        cout << "Item is found at location " << loc << endl; 
    } 
} 

int main()
{
    int arr[]= {2,4,6,8};
    int size= sizeof(arr)/ sizeof(arr[0]);

    LinearSearch(arr, size);
    
    return 0;
}