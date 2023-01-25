#include <iostream>
using namespace std;

int matrix[4][4];
int count=0;


void Display(int v)
{
    for (int i=0; i<v; i++)
    {
        for (int j=0; j<v; j++)
        {
            cout << matrix[i][j]<< " ";
        }
        cout << endl;
    }
}

void AddEdge(int row, int column)
{
    matrix[row][column]=1;
    matrix[column][row]=1;
}

void RemoveEdge(int row, int column)
{
    matrix[row][column]=0;
    matrix[column][row]=0;
}


int main()
{
    int v=4; 
    AddEdge(0,1); 
    AddEdge(0,2); 
    AddEdge(1,2); 
    AddEdge(2,3);
    cout << "Adjacency Matrix: " << endl; 
    Display(v);
    RemoveEdge(1,2); 
    cout << "Adjacency Matrix after Removing an Edge: " << endl; 
    Display(v);
    return 0;
}