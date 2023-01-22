#include <iostream>
using namespace std;

int front = -1, rear = -1;

// TO DISPLAY THE ELEMENTS OF A QUEUE
void enqueue_peek(int queue[])
{
    for (int i = 0; i <= rear; i++)
    {
        cout << queue[i] << ' ';
    }
    cout << endl;
}

void dequeue_peek(int queue[])
{
    for (int i = rear; i >= front; i--)
    {
        cout << queue[i] << ' ';
    }
    cout << endl;
}

// ENQUEUE OPERATION:
void enqueue(int queue[], int item, int size)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        cout << "Queue Overflow" << endl;
        return;
    }

    else if (front == -1)
    {
        front = 0;
        rear = 0;
    }

    else if (rear == size - 1)
    {
        rear = 0;
    }

    else
    {
        rear += 1;
    }

    queue[rear] = item;
    enqueue_peek(queue);
}

// DEQUEUE OPERATION:
void dequeue(int queue[], int size)
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    else
    {
        dequeue_peek(queue);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        else if (front == size - 1)
        {
            front = 0;
        }
        
        else
        {
            front += 1;
        }
    }
}


int main()
{
    int size = 3;
    int queue[3];

    cout << "Enqueue Operation" << endl;
    cout << "Elements inserted in a Queue: " << endl;
    enqueue(queue, 12, size);
    enqueue(queue, 14, size);
    enqueue(queue, 19, size);
    enqueue(queue, 10, size);

    cout << "\nDequeue Operation" << endl;
    cout << "Queue After Dequeue" << endl;
    dequeue(queue, size);
    dequeue(queue, size);
    dequeue(queue, size);
    dequeue(queue, size);

    return 0;
}