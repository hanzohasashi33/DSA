#include<bits/stdc++.h>
using namespace std;
 
 
class Graph
{
	int V;
	vector<int> *adj;
  public:
	  Graph(int V)
	  {
		  this->V = V;
		  adj = new vector<int>[V];
	  }
	  ~Graph()
	  {
		  delete[] adj;
	  }
	  void addEdge(int u,int v);
	  bool dfs(bool visited[],int s,int color[]);
	  bool isBipartite();
};
 
void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
 
bool Graph::dfs(bool visited[],int s,int color[])
{
	for(auto i=adj[s].begin();i!=adj[s].end();i++)
	{
		if(!visited[*i])
		{
			visited[*i] = true;
			color[*i] = !color[s];
 
			if(!dfs(visited,*i,color))
				return false;
		}
		else if(color[*i]==color[s])
			return false;
	}
	return true;
}
 
bool Graph::isBipartite()
{
	int color[V];
	for(int i=0;i<V;i++)
		color[i] = -1;
	bool visited[V]={0};
 
 
	visited[0]=true;
	color[0]=0;
	if(dfs(visited,1,color))
			return true;
	return false;
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
    g.addEdge(x,y);
  }
 
	bool flag = g.isBipartite();
  cout << flag << endl;
	return 0;
}
