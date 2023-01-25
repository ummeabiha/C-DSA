#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue <int> Queue;

    Queue.push(12);
    Queue.push(14);
    Queue.push(19);

    while(!Queue.empty())
    {
        cout << Queue.front() << ' ';
        Queue.pop();
    }
    return 0;
}

