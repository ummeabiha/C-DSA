#include <iostream>
using namespace std;

void traverse(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
}

void BubbleSort(int arr[], int size)
{
    int j=0;
    for (int i=0; i<size; i++)
    {
        int count=0;
        for (j=0; j<size-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp= arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                count++;
            }
        }
                
        if(count==0)
        {
            break;
        }
        else
        {
            j++;
        }
    }
}

int main()
{
    int arr[]={2,3,7,1,9};
    int size= sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,size);
    traverse(arr,size);
    return 0;
}