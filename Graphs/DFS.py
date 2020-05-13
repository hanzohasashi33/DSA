from collections import defaultdict

class Graph :
    def __init__(self) :
        self.graph = defaultdict(list)

    def addedge(self,u,v) :
        self.graph[u].append(v)


    def DFSUtil(self,v,visited) :

        visited[v] = True 
        print(v,end = " ")

        for i in self.graph[v] :
            if visited[i] == False :
                self.DFSUtil(i,visited)

    def DFS(self,v) : 
        visited = [False] * len(self.graph)
        self.DFSUtil(v,visited)


if __name__ == "__main__":
    g = Graph() 
    g.addedge(0,1)
    g.addedge(0,2)
    g.addedge(1,2)
    g.addedge(2,0)
    g.addedge(2,3)
    g.addedge(3,3)

    print("DFS :")
    g.DFS(2)