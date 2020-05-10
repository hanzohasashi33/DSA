#include <bits/stdc++.h>
using namespace std;


class Graph 
{
  int V;
  list <pair <int,int>> *adj;
  public :
    Graph(int V);
    void Addedge(int u,int v,int w);
    void shortestpath(int s,int d);
};



Graph :: Graph(int V)
{
  this->V = V;
  adj = new list <pair <int,int>> [V];
}


void Graph::Addedge(int u,int v,int w)
{
  adj[u].push_back(make_pair(v,w));
  adj[v].push_back(make_pair(u,w));
}


void Graph::shortestpath(int src,int dest)
{
  set <pair <int,int>> setds;
  vector<int> dist(V,INT_MAX);

  setds.insert(make_pair(0,src));
  dist[src] = 0;

  while(!setds.empty())
  {
    pair <int,int> temp = *(setds.begin());
    setds.erase(setds.begin());

    int u = temp.second;
    list< pair<int, int> >::iterator i; 
    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    { 
      int v = (*i).first; 
      int weight = (*i).second; 

      if (dist[v] > dist[u] + weight) 
      { 
        if (dist[v] != INT_MAX) 
          setds.erase(setds.find(make_pair(dist[v], v))); 

        dist[v] = dist[u] + weight; 
        setds.insert(make_pair(dist[v], v)); 
      } 
    } 
  } 
  
  
  //printf("Vertex   Distance from Source\n"); 
  //for (int i = 0; i < V; ++i) 
    //printf("%d \t\t %d\n", i, dist[i]); 

  for(int i = 0;i < V;++i)
  {
    if(i == dest) 
    {
      cout << dist[i] << endl;
      break;
    }
  }
}



int main()
{
  int n,m;
  cin >> n >> m;
  Graph g(n);

  for(int i = 0;i < m;i++)
  {
    int x,y,w;
    cin >> x >> y >> w;
    g.Addedge(x-1,y-1,w);
  }
  int source,destination;
  cin >> source >> destination;
  g.shortestpath(source-1,destination-1);
  return 0;
}
