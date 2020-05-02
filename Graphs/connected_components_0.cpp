//0 based indexing
#include <bits/stdc++.h>
using namespace std;


class Graph
{
  int V;
  list <int> *adj;
  void DFSUtil(int v, bool visited[]);
  public :
    Graph(int V);
    void addedge(int v,int w);
    int connectedcomponents();
};



int Graph::connectedcomponents()
{
  int count = 0;
  bool * visited = new bool[V];

  for(int v = 0;v < V;v++) visited[v] = false; 
  
  for(int v = 0;v < V;v++) 
  {
    if(visited[v] == false)
    {
      DFSUtil(v,visited);
      //cout << endl;
      count ++;
    }
  }
  delete[] visited;
  return count;
}




void Graph::DFSUtil(int v,bool visited[])
{
  visited[v] = true;
  //cout << v << " ";

  list <int> :: iterator i;
  for(i = adj[v].begin();i != adj[v].end();i++)
  {
    if(!visited[*i])
    {
      DFSUtil(*i,visited);
    }
  }
}


Graph::Graph(int V)
{
  this->V = V;
  adj = new list <int> [V];
}


void Graph::addedge(int v,int w)
{
  adj[v].push_back(w);
  adj[w].push_back(v);
}


int main()
{
  int n,m;
  cin >> n >> m;
  Graph g(n);
  for(int i = 0;i < m;i++)
  {
    int x,y;
    cin >> x >> y;
    g.addedge(x,y);
  }
  cout << g.connectedcomponents() << endl;
  return 0;
}
