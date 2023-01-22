#include <iostream>
using namespace std;

void traverse(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion(int arr[], int &size)
{
    int num, element, index=0;
    cout << "Enter the number of elements you want to insert: " << endl;
    cin >> num;

    for(int i=0; i<num; i++)
    {
        cout << "Enter the element you want to insert: " << endl;
        cin >> element;
        cout << "Enter the index of element: " << endl;
        cin >> index;

        for (int j=size; j >= index; j--)
        {
            arr[j + 1] = arr[j];  //shift the value on index 3 to index 4
        }
        arr[index] = element;
        size++;
    }
}

void deletion(int arr[], int &size)
{
    int element, num, index=0;
    cout << "Enter the number of elements you want to delete: " << endl;
    cin >> num;

    for(int i=0; i<num; i++)
    {
        cout << "Enter the element you want to delete: " << endl;
        cin >> element;
        cout << "Enter the index: " << endl;
        cin >> index;

        for (int j=index; j<size-1; j++)
        {
            arr[j] = arr[j + 1]; //shift the 4th element to 3rd element
        }
        size--;
    }
}

int main()
{
    int arr[]={2,4,6,8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Traversal: " << endl;
    traverse(arr, size);

    cout << "Insertion: " << endl;
    insertion(arr, size);

    cout << "\nAfter Insertion: " << endl;
    traverse(arr, size);

    cout << "\nDeletion: " << endl;
    deletion(arr, size);

    cout << "\nAfter Deletion: " << endl;
    traverse(arr, size);

    return 0;
}