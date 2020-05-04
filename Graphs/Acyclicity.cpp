#include <bits/stdc++.h>
using namespace std;



class Graph
{
  int V;
  list <int> *adj;

  public :
    Graph(int V);
    void addedge(int v,int w);
    bool iscyclicUtil(int v,bool visited[],bool *rs);
    bool iscyclic();
};



Graph :: Graph(int V)
{
  this->V = V;
  adj = new list <int> [V];
}



void Graph::addedge(int v,int w)
{
  adj[v].push_back(w);
}



bool Graph::iscyclicUtil(int v,bool visited[],bool * rstack)
{
  if(visited[v] == false)
  {
    visited[v] = true;
    rstack[v] = true;

    list <int> :: iterator i;
    for(i = adj[v].begin();i != adj[v].end();++i)
    {
      if(!visited[*i] && iscyclicUtil(*i,visited,rstack)) return true;
      else if(rstack[*i]) return true;
    }
  }

  rstack[v] = false;
  return false;
}




bool Graph::iscyclic()
{
  bool * visited = new bool[V];
  bool * rstack = new bool[V];

  for(int i = 1;i < V;i++)
  {
    visited[i] = false;
    rstack[i] = false;
  }

  for(int i = 1;i < V;i++)
  {
    if(iscyclicUtil(i,visited,rstack)) return true;
  }

  return false;
}






int main()
{
  int n,m;
  cin >> n >> m;
  Graph g(n + 1);
  for(int i = 0;i < m;i++)
  {
    int x,y;
    cin >> x >> y;
    g.addedge(x,y);
  }
  cout << g.iscyclic() << endl;
  return 0;
}
