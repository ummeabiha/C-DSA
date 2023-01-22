#include <iostream>
using namespace std;

//Function Prototype
int BinarySearch(int arr[], int beg, int end, int item);

int main()
{
    int arr[]={2,5,5,5,6,6,8,9,9,9};
    int beg=0, end=10, item;

    cout << "Enter the element you want to search " << endl;
    cin >> item;

    int search= BinarySearch(arr,beg,end,item);
    
    if (search==-1)
    {
        cout << "Element is not found" << endl;
    }
    
    else if (search==1)
    {
        cout << "Element " << item << " occurs " << search << " time" << endl;
    }

    else
    {
        cout << "Element " << item << " occurs " << search << " times" << endl;
    }

    return 0;
}


int BinarySearch(int arr[], int beg, int end, int item)
{
    int loc=0, count=0;
    int mid=(beg+end)/2;

    while(beg<end && arr[mid]!=item)
    {
        if (item<arr[mid])
        {
            count+=1;
            end=mid-1;
        }

        else
        {
            
            beg= mid+1;
        }

        mid= (beg+end)/2;
    }


    if(arr[mid]==item)
    {
        loc=mid;

        int count=0;
        for (int i=0; i<end; i++)
        {
            if (arr[i]==arr[loc])
            {
                count +=1;
            }
        }

        return count;
    }

    else
    {
        loc=-1;
        return loc;
    }
    
}

