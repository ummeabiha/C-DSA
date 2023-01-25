#include <iostream>
#include <queue>
using namespace std;

const int n = 3;

class Queue
{
public:
    int front = -1, rear = -1, queue[n];

    void Enqueue(int item)
    {
        if ((front == 0 && rear == n - 1) || (front == rear+1))
        {
            cout << "\nQueue Overflow." << endl;
            return;
        }

        else if (front == -1)
        {
            front = 0;
            rear = 0;
        }

        else if (rear == n - 1)
        {
            rear = 0;
        }

        else
        {
            rear++;
        }

        queue[rear] = item;
        cout << "\nEnqueue: " << queue[rear] << " ";
    }

    void Dequeue()
    {
        if(front!=-1)
        {
            cout << "\nDequeue: " << queue[front] << " ";
        }
        
        if (front == -1 && rear == -1)
        {
            cout << "\nQueue Underflow." << endl;
            return;
        }

        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        else if (front == n - 1)
        {
            front = 0;
        }

        else
        {
            front+=1;
        }
    }
};

int main()
{
    Queue q;
    q.Enqueue(12);
    q.Enqueue(14);
    q.Enqueue(19);
    q.Enqueue(10);

    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    return 0;
}