#include <bits/stdc++.h>
using namespace std;


struct Edge {
  int src,dest,weight;
};


struct Graph {
  int V,E;
  struct Edge * edge;
};


struct Graph * creategraph(int V,int E)
{
  struct Graph * graph = new Graph;
  graph->V = V;
  graph->E = E;
  graph->edge = new Edge[graph->E];
  return graph;
}


bool isnegcycle(struct Graph * graph,int src)
{
  int V = graph->V;
  int E = graph->E;
  int dist[V];

  for(int i = 0;i < V;i++)
  {
    dist[i] = INT_MAX;
  }  
  dist[src] = 0;

  for(int i = 1;i <= V - 1;i++)
  {
    for(int j = 0;j < E;j++)
    {
      int u = graph->edge[j].src;
      int v = graph->edge[j].dest;
      int weight = graph->edge[j].weight;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
        dist[v] = dist[u] + weight; 
    }
  }
  for (int i = 0; i < E; i++) 
  { 
    int u = graph->edge[i].src; 
    int v = graph->edge[i].dest; 
    int weight = graph->edge[i].weight; 
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
      return true; 
  }
  return false;
}


int main()
{
  int n,m;
  cin >> n >> m;
  struct Graph*graph = creategraph(n,m);

  for(int i = 0;i < m;i++)
  {
    int x,y,w;
    cin >> x >> y >> w;
    graph->edge[i].src = x;
    graph->edge[i].dest = y;
    graph->edge[i].weight = w; 
  }
  cout << isnegcycle(graph,0);
  return 0;
}
