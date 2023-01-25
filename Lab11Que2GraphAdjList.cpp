#include <iostream>
#include<list>
using namespace std;

class Graph
{
    int v;
    list <int> *l;
    public:
    Graph(int V)
    {
        v=V;
        l= new list<int>[v];
    }

    void AddEdge(int row, int column)
    {
        l[row].push_back(column);
        l[column].push_back(row);
    }

    void Display()
    {
        for(int i=0; i<v; i++)
        {
            cout << "Adjacent Elements of " << i << "--->" << " ";
            for (int j:l[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
        
    }
};


int main()
{
    Graph g(4); 
    g.AddEdge(0,1); 
    g.AddEdge(0,2); 
    g.AddEdge(1,2); 
    g.AddEdge(2,3); 
    g.Display(); 
    
    return 0;
}