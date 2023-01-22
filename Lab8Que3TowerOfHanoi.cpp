#include <iostream>
using namespace std;

int TowerOfHanoi(int n, char beg, char aux, char end)
{
    if (n<=1)
    {
        cout << "Move disk " << n << " from " << beg << " to " << end << endl;
    }
    else
    {
        TowerOfHanoi(n-1, beg, end, aux);
        cout << "Move disk " << n << " from " << beg << " to " << end << endl;
        TowerOfHanoi(n-1, aux, beg, end);
    }
}


int main()
{
    int num;
    cout << "Enter the number of disks: " << endl;
    cin >> num;
    TowerOfHanoi(num, 'A', 'B', 'C');
    
    return 0;
}