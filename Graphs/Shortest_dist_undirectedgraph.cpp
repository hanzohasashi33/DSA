#include <bits/stdc++.h>
using namespace std;

class Graph
{
  int V;
  list <int> * adj;

  public :
    Graph(int V);
    void addedge(int v,int w);
    bool BFS(int src,int dest,int pred[],int dist[]);
    void printShortestDistance(int s,int dest);
};




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


bool Graph::BFS(int src,int dest,int pred[],int dist[])
{
  list <int> queue;
  bool visited[V];

  for(int i = 0;i < V;i++)
  {
    visited[i] = false;
    dist[i] = INT_MAX;
    pred[i] = -1;
  }

  visited[src] = true;
  dist[src] = 0;
  queue.push_back(src);
  list <int> :: iterator i;
  while(!queue.empty())
  {
    int u = queue.front();
    queue.pop_front();

    for(i = adj[u].begin();i != adj[u].end();i++)
    {
      if(visited[*i] == false)
      {
        visited[*i] = true;
        dist[*i] = dist[u] + 1;
        pred[*i] = u;
        queue.push_back(*i);
      }

      if(*i == dest)
      {
        return true;
      }
    }
  }
  return false;
}







void Graph::printShortestDistance(int s,int dest) 
{
  int pred[V],dist[V];

  if(BFS(s,dest,pred,dist) == false) return ;

  vector <int> path;
  int crawl = dest;
  path.push_back(crawl);
  while(pred[crawl] != -1)
  {
    path.push_back(pred[crawl]);
    crawl = pred[crawl];
  }

  cout << dist[dest];
  /*for(int i = path.size() - 1;i >= 0;i--)
  {
    cout << path[i] << " ";
  }*/
}







int main() {
  int n, m;
  std::cin >> n >> m;
  Graph g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    g.addedge(x,y);
  }
  int s, t;
  std::cin >> s >> t;
  g.printShortestDistance(s,t);
  return 0;
}
