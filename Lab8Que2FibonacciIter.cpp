#include <iostream>
using namespace std;

void Fibonacci(int n)
{
    int prevNum=1, currNum=1, prevprevNum=0;
    cout << "Term 1: " << prevNum << endl;
    cout << "Term 2: " << currNum << endl;

    for(int i=3; i<=n; i++)
    {
        prevprevNum= prevNum; //1st iter--> Term1(1), 2nd iter--> Term2(1), 3rd iter--> Term3(2)
        prevNum= currNum; //1st iter--> Term2(1), 2nd iter--> Term3(2), 3rd iter--> Term4(3)
        currNum= prevprevNum+prevNum; //1st iter--> 2, //2nd iter--> 3, //3rd iter--> Term2(5)
        cout << "Term " << i << ": " << currNum << endl;
    }
}

int main()
{
    int num;
    cout << "Enter the element: " << endl;
    cin >> num;
    Fibonacci(num);

    return 0;
}