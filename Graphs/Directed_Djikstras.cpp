#include<iostream> 
#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 
  

class AdjListNode 
{ 
    int v; 
    int weight; 
public: 
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;} 
    int getV()       {  return v;  } 
    int getWeight()  {  return weight; } 
}; 
  

class Graph 
{ 
    int V;    
    list<AdjListNode> *adj; 
  
 
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
    Graph(int V);   
  
    void addEdge(int u, int v, int weight); 
  
    void shortestPath(int s,int d); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<AdjListNode>[V]; 
} 
  
void Graph::addEdge(int u, int v, int weight) 
{ 
    AdjListNode node(v, weight); 
    adj[u].push_back(node); // Add v to u's list 
} 
  

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) 
{ 
    visited[v] = true; 
  
    list<AdjListNode>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    { 
        AdjListNode node = *i; 
        if (!visited[node.getV()]) 
            topologicalSortUtil(node.getV(), visited, Stack); 
    } 
  
    
    Stack.push(v); 
} 
  

void Graph::shortestPath(int s,int d) 
{ 
    stack<int> Stack; 
    int dist[V]; 
  
    
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
  
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            topologicalSortUtil(i, visited, Stack); 
  

    for (int i = 0; i < V; i++) 
        dist[i] = INF; 
    dist[s] = 0; 
  
    // Process vertices in topological order 
    while (Stack.empty() == false) 
    { 
        // Get the next vertex from topological order 
        int u = Stack.top(); 
        Stack.pop(); 
  
        // Update distances of all adjacent vertices 
        list<AdjListNode>::iterator i; 
        if (dist[u] != INF) 
        { 
          for (i = adj[u].begin(); i != adj[u].end(); ++i) 
             if (dist[i->getV()] > dist[u] + i->getWeight()) 
                dist[i->getV()] = dist[u] + i->getWeight(); 
        } 
    } 
  
    // Print the calculated shortest distances 
    for (int i = 0; i < V; i++) 
      if (i == d) 
      {
        (dist[i] == INF)? cout << "-1 ": cout << dist[i] ;
        break;
      } 
} 
  
// Driver program to test above functions 
int main() 
{ 
  int n,m;
  cin >> n >> m;
  Graph g(n);

  for(int i = 0;i < m;i++)
  {
    int x,y,w;
    cin >> x >> y >> w;
    g.addEdge(x-1,y-1,w);
  }
  int source,destination;
  cin >> source >> destination;
  g.shortestPath(source-1,destination-1);
  return 0; 
} 
