#include <iostream>
using namespace std;

void TOH(int n, char beg, char aux, char end)
{
    if (n<=1)
    {
        cout << "Disk is moved from " << beg << " to " << end << endl;
    }
    else
    {
        TOH(n-1, beg, end, aux);
        cout << "Disk is moved from " << beg << " to " << end << endl;
        TOH(n-1, aux, beg, end);
    }
}


int main()
{
    int num;
    cout << "Enter the number of disks: " << endl;
    cin >> num;
    TOH(num, 'A', 'B', 'C');
    
    return 0;
}