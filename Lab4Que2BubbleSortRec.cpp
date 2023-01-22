#include <iostream>
using namespace std;

void traverse(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
}

void BubbleSortRecc(int arr[], int size)
{
    if (size==1)
    {
        return;
    }
    else
    {
        for(int i=0; i<size;i++)
        {
            if (arr[i]>arr[i+1])
            {
                int temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
            }
        }
    }
    BubbleSortRecc(arr, size-1);
}


int main()
{
    int arr[]={4, 7, 8, 10, 2};
    int size= sizeof(arr)/ sizeof(arr[0]);
    BubbleSortRecc(arr, size);
    traverse(arr,size);
    return 0;
}