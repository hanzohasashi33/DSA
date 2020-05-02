//1 based indexing
#include <bits/stdc++.h>
using namespace std;


class Graph
{
  int V;
  list <int> *adj;
  

  public :
    Graph(int v);
    void addedge(int v,int w);
    void topsort();
    void topsortUtil(int v,bool visited[],stack <int> &s);
};



Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}



void Graph::addedge(int v,int w)
{
  adj[v].push_back(w);
}



void Graph::topsortUtil(int v,bool visited[],stack <int> &s)
{
  visited[v] = true;

  list <int> :: iterator i;
  for(i = adj[v].begin();i != adj[v].end();i++)
  {
    if(!visited[*i])
    {
      topsortUtil(*i,visited,s);
    }
  }
  s.push(v);
}




void Graph::topsort()
{
  stack <int> s;

  bool * visited = new bool[V];
  for(int i = 1;i < V;i++) visited[i] = false;

  for(int i = 1;i < V;i++)
  {
    if(visited[i] == false) topsortUtil(i,visited,s);
  }

  while(s.empty() == false)
  {
    cout << s.top() << " ";
    s.pop();
  }
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
  g.topsort();
  return 0;
}
