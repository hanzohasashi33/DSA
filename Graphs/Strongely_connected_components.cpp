#include <bits/stdc++.h>
using namespace std;


class Graph
{
  int V;
  list <int> *adj;

  public :
    Graph(int V);
    void addedge(int v,int w);
    int printSCC();
    Graph gettranspose();
    void fillOrder(int v,bool visited[],stack <int> &s);
    void DFSUtil(int v,bool visited[]);
};



Graph::Graph(int V)
{
  this->V = V;
  adj = new list <int> [V];
}


void Graph::DFSUtil(int v,bool visited[])
{
  visited[v] = true;
  //cout << v << " ";

  list <int> :: iterator i ;
  for(i = adj[v].begin();i != adj[v].end();++i)
  {
    if(!visited[*i])
    {
      DFSUtil(*i,visited);
    }
  }
}



Graph Graph::gettranspose()
{
  Graph g(V);
  for(int v = 0;v < V;v++)
  {
    list <int> :: iterator i;

    for(i = adj[v].begin();i != adj[v].end();++i)
    {
      g.adj[*i].push_back(v);
    }
  }
  return g;
}


void Graph::addedge(int v,int w)
{
  adj[v].push_back(w);
}



void Graph::fillOrder(int v,bool visited[],stack <int> &s)
{
  visited[v] = true;
  list <int> :: iterator i;
  for(i = adj[v].begin();i != adj[v].end();i++)
  {
    if(!visited[*i])
    {
      fillOrder(*i,visited,s);
    }
  }
  s.push(v);
}



int Graph::printSCC()
{
  int count = 0;
  stack <int> s;
  bool *visited = new bool [V];
  for(int i = 0;i < V;i++) visited[i] = false;

  for(int i = 0;i < V;i++) 
  {
    if(visited[i] == false)
    {
      fillOrder(i,visited,s);
    }
  }

  Graph g_rev = gettranspose();

  for(int i = 0;i < V;i++)
  {
    visited[i] = false;
  }


  while(!s.empty())
  {
    int x = s.top();
    s.pop();

    if(visited[x] == false)
    {
      g_rev.DFSUtil(x,visited);
      //cout << endl;
      count ++;
    }
  }

  return count;
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
  cout << g.printSCC() << endl;
  return 0;
}
