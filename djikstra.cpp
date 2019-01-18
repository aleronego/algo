//Djikstra w STL
#include <iostream>
#include <list>
#include <vector>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
 
class Graph
{
    int V;
    list< pair<int,int> > *adj;
    set< pair<int,int> > setds;
    vector<int> dist;

    void djikstra(int);
    void printDist();
    void printAdj();
    void printRoute(int, int);

public:
    Graph(int);
    void addEdge(int, int, int);
    void searchAndPrint(int, int);
};

Graph::Graph(int v) : V(v)
{
    adj = new list< pair<int,int> >[V];
    dist = vector<int> (V, INF );
}

void Graph::addEdge(int a, int b, int dist)
{
    adj[a].push_back( make_pair(b, dist) );
    adj[b].push_back( make_pair(a, dist) );
}

void Graph::djikstra(int s) 
{
    setds.insert(make_pair(0, s));
    dist[s] = 0;

    while(!setds.empty())
    {
        pair<int,int> temp = *(setds.begin());
        setds.erase(setds.begin());

        int tempV = temp.second;

        for(auto it = adj[tempV].begin(); it != adj[tempV].end(); ++it)
        {
            int v = (*it).first;
            int weight = (*it).second;
            if(dist[v]>dist[tempV]+weight)
            {
                if(dist[v]!=INF)                
                    setds.erase(setds.find(make_pair(dist[v], v)));
                
                dist[v]=dist[tempV]+weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
}

void Graph::printDist()
{
    cout << "V\tDist\n";
    for(int i = 0; i < V; ++i)
        cout << i << "\t" << dist[i] << endl;
    cout << endl;
}

void Graph::printAdj()
{
    cout << "\nAdj\n";
    for(int i = 0; i < V; ++i)
    {
        cout << endl << i << endl;
        for(auto it = adj[i].begin(); it != adj[i].end(); ++it)
        {
            cout << (*it).first << " " << (*it).second << endl;
        }
    }
    cout << endl;
}

void Graph::printRoute(int s, int to)
{
    cout << "Reverse route " << s << " to " << to << " ";
    list<int>queue;
    queue.push_back(to);
    while(!queue.empty())
    {
        int temp = queue.back();
        queue.pop_back();
        int min = temp;
        for(auto it = adj[temp].begin(); it != adj[temp].end(); ++it)
        {
            int curr = (*it).first;
            if(dist[curr] < dist[min])
                min = curr; 
        }

        if(min!=s)
            queue.push_back(min);
        cout << min << " ";
    }
    cout << endl;
}

void Graph::searchAndPrint(int start, int to)
{
    djikstra(start);
    printRoute(start,to);
}


int main()
{
    Graph g(9);

    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 

    g.searchAndPrint(0, 4);

    return 0;
}