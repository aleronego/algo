//Depth First Search
//   0
//  / \\
// 1 - 2 
//     |
//   3=3
///////////
#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool *visited;
public:   
    Graph(int);
    void addEdge(int, int);
    void DFS(int);
};
    
Graph::Graph(int v) : V(v)
{
    adj = new list<int>[V];
    visited = new bool[V];
    for(int i = 0; i < V; ++i)
        visited[i]=false;
}

void Graph::addEdge(int a, int b)
{
    adj[a].push_back(b);
}

void Graph::DFS(int v)
{
    cout << v << " ";
    visited[v]=true;
    for(auto it = adj[v].begin(); it != adj[v].end(); ++it)
        if(!visited[*it])
            DFS(*it);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    
    int start = 2;
    cout << "Start DFS node " << start << endl;
    g.DFS(start);

    return 0;
}