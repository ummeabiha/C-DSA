#include <iostream>
using namespace std;

void Traverse(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Insert(int arr[], int &size)
{
    int element, index;
    cout << "Enter the element you want to insert: " << endl;
    cin >> element;
    cout << "Enter the index at which you want to insert: " << endl;
    cin >> index;

    for (int i=size; i>=index; i--)    
    {
        arr[i+1]= arr[i];
    }
    arr[index]=element;
    size++;
}

void Delete(int arr[], int &size)
{
    int element, index;
    cout << "Enter the element you want to delete: " << endl;
    cin >> element;
    cout << "Enter the index at which you want to delete: " << endl;
    cin >> index;

    for (int i=index; i<=size; i++)    
    {
        arr[i]= arr[i+1];
    }
    size--;

}

// LINEAR SEARCH ALGORITHM
void LinearSearch(int arr[], int size)
{
    int element, index, loc=0;
    cout << "Enter the element you want to search: " << endl;
    cin >> element;
    arr[size+1]= element;

    while (arr[loc]!=element)
    {
        loc++;
    }

    if(loc==size+1)
    {
        cout << "Item not Found!" << endl;
    }
    
    else
    {
        cout << "Item Found at Location " << loc << endl;
    }
}



// BINARY SEARCH ALGORITHM
int BinarySearchFirst(int arr[], int n, int item)
{
    int low = 0, high = n, mid = 0, ans = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == item)
        {
            ans = mid;
            high = mid - 1;
        }

        else if (arr[mid] < item)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

// Finds Last Occurence
int BinarySearchLast(int arr[], int n, int item)
{
    int low = 0, high = n, mid = 0, ans = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == item)
        {
            ans = mid;
            low = mid + 1;
        }

        else if (arr[mid] < item)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

// Finds All Occurences
void BinarySearchAll(int arr[], int n)
{
    int occ, item;
    cout << "Enter the element yo want to search: " << endl;
    cin >> item;
    int first = BinarySearchFirst(arr, n, item);
    int last = BinarySearchLast(arr, n, item);

    if (first == -1)
    {
        cout << "Element is not Found!" << endl;
    }
    else
    {
        occ = last - first + 1;
        cout << "Element is Found at Location: " << occ  << endl;
    }
}



//BUBBLE SORTING
void BubbleSortIter(int arr[], int size)
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


//BUBBLE SORTING RECURSIVE
void BubbleSortRec(int arr[], int size)
{
    if (size==1)
    {
        return;
    }
    else
    {
        for (int i=0; i<size; i++)
        {
            if (arr[i]>arr[i+1])
            {
                int temp= arr[i+1];
                arr[i+1]=arr[i];
                arr[i]= temp;
            }
        }
        BubbleSortRec(arr, size-1);
    }
}



int main()
{
    int arr[4]={2,4,6,8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Traversal: " << endl;
    Traverse(arr,size);
        
    cout << "Insertion: " << endl;
    Insert(arr, size);

    cout << "\nAfter Insertion: " << endl;
    Traverse(arr, size);

    cout << "\nDeletion: " << endl;
    Delete(arr, size);

    cout << "\nAfter Deletion: " << endl;
    Traverse(arr, size);

    cout << "\nLinear Search: " << endl;
    LinearSearch(arr, size);

    cout << "\nBinary Search: " << endl;
    BinarySearchAll(arr, size);

    cout << "\nBubble Sort Iterative: " << endl;
    BubbleSortIter(arr, size);
    Traverse(arr, size);

    cout << "\nBubble Sort Recursive: " << endl;
    BubbleSortRec(arr, size);
    Traverse(arr, size);

    return 0;
}