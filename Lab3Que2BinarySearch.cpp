#include <iostream>
using namespace std;

// Finds First Occurence
int BinarySearchfirst(int arr[], int n, int item)
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
int BinarySearchlast(int arr[], int n, int item)
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
int BinarySearchAll(int arr[], int n, int item)
{
    int occ;
    int first = BinarySearchfirst(arr, n, item);
    int last = BinarySearchlast(arr, n, item);

    if (first == -1)
    {
        return 0;
    }
    else
    {
        occ = last - first + 1;
    }
    return occ;
}

int main()
{
    int item;
    int arr[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "ENTER THE ELEMENT YOU WANT TO SEARCH: " << endl;
    cin >> item;

    int allOcc= BinarySearchAll(arr, size, item);
    int firstOcc= BinarySearchfirst(arr, size, item);

    cout << "Element occurs " << allOcc << " times in an array." << endl;
    
    if (firstOcc==-1 && allOcc==0)
    {
        cout << "Element is not found in the array" << endl;
    }
    else
    {
        cout << "Element is found at location " << allOcc << " in the array" << endl;
    }
    return 0;
}