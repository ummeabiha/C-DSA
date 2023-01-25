#include <iostream>
#include<queue>
using namespace std;

/*
ALGORITHM:
Let s= root node.
1- Start with node s and enqueue it to the queue.
2- Repeat the following steps for all nodes in graph.
3- Dequeue S and process it.
4- Enqueue all the adjacent nodes of s and process them.
5- End.
*/

int main()
{
    int visited[4]={}; //array for storing the visited elements
    queue <int> q;
    
    int graph[4][4]={{0,1,1,0},{1,0,1,0},{1,1,0,1},{0,0,1,0}}; //graph
    
    int startnode=0;
    visited[startnode]=1;
    q.push(startnode);

    while(!q.empty())
    {
        int node= q.front();
        q.pop();
        cout << node <<endl;

        for(int i=0; i<4; i++)
        {
            if(graph[node][i]==1 && visited[i]==0) //checks if the adj node is present and not in the visited array
            {
                visited[i]=1;
                q.push(i);
            }
        }
    }

    return 0;
}