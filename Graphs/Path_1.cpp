//1 based indexing
#include <bits/stdc++.h>
using namespace std;



class graph
{
    int V;    //no of vertices
    list <int> *adj;       //pointer to array of lists

    public :
        graph(int V);    //graph constructor
        void addedge(int v,int w);
        bool isreach(int s,int d);  
};



graph::graph(int V)
{
    this->V = V;
    adj = new list <int>[V];
}


void graph::addedge(int v,int w)
{
    adj[v-1].push_back(w-1);     //add w to v list
    adj[w-1].push_back(v-1);     //add v to w list
}



bool graph::isreach(int s,int d)
{
    if(s == d) return true;

    bool *visited = new bool[V];
    for(int i = 0;i < V;i++) visited[i] = false;

    list <int> queue;

    visited[s] = true;
    queue.push_back(s);

    list <int> :: iterator i;

    while(!queue.empty())
    {
        s = queue.front();
        queue.pop_front();

        for(i = adj[s].begin();i != adj[s].end();++i)
        {
            if(*i == d) return true;

            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    return false;
}








int main()
{
    int n,m;          //n-vertices
    cin >> n >> m;
    graph g(n);
    for(int i = 0;i < m;i++)
    {
        int x,y;
        cin >> x >> y;
        g.addedge(x,y);
    }
    int s,d;
    cin >> s >> d;
    cout << g.isreach(s-1,d-1) << endl;
    return 0;
}
