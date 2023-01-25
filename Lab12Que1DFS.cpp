#include <iostream>
#include<stack>
using namespace std;

int main()
{
    int visited[4]={}; //array for storing the visited elements
    stack <int> s;
    int graph[4][4]={{0,1,1,0},{1,0,1,0},{1,1,0,1},{0,0,1,0}}; //graph
    
    int startnode=0;
    visited[startnode]=1;
    s.push(startnode);

    while(!s.empty())
    {
        int node= s.top();
        s.pop();
        cout << node <<endl;
        for(int i=0; i<4; i++)
        {
            if(graph[node][i]==1 && visited[i]==0) //checks if the adj node is present and not in the visited array
            {
                visited[i]=1;
                s.push(i);
            }
        }
    }
    return 0;
}