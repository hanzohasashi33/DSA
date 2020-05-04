#include <bits/stdc++.h>
using namespace std;


class Graph
{
    int V;
    list <int> *adj;

    public :
        Graph(int V);
        void addedge(int v, int w);
        void BFS(int s);
};



Graph :: Graph(int V)
{
    this->V =V;
    adj = new list <int>[V];
}


void Graph:: addedge(int v,int w)
{
    adj[v].push_back(w);
}


void Graph ::BFS(int s)    //s = source node
{
    //set all vertices as not visited
    bool *visited = new bool[V];
    int *distance = new int[V];
    int count = -1;
    for(int i = 0;i < V;i++)
    {
        distance[i] = INT_MAX;
    }
    
    for(int i = 0;i < V;i++)
    {
        visited[i] = false;
    }

    //create a queue for BFS
    list <int> q;
    
    visited[s] = true;
    q.push_back(s);
    distance[s] = 0;
    list<int> :: iterator i;

    while(!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop_front();
        count ++;
        for(i = adj[s].begin();i != adj[s].end(); ++i)
        {
            if(distance[*i] == INT_MAX)      //notvisited[*i]
            {
                visited[*i] = true;
                q.push_back(*i);
                distance[*i] = distance[s] + 1;
            }
        }
    }

    cout << endl;
    for(int i = 0;i < V;i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;
}




int main()
{
    Graph g(5);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,4);

    cout << "BFS : " ;
    g.BFS(2);
    return 0;
}
