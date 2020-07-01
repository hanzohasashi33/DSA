from collections import defaultdict

class Graph :
    def __init__(self,V) :
        self.V = V
        self.graph = defaultdict(list)

    def DFSUtil(self,temp,v,visited) :
        visited[v] = True 
        temp.append(v)

        for i in self.graph[v] :
            if visited[i] == False :
                temp = self.DFSUtil(temp,i,visited)
        return temp

    def addEdge(self,v,w) :
        self.graph[v].append(w)
        self.graph[w].append(v)

    def connectedcomponents(self) :
        visited = [False] * self.V 
        cc = []

        for v in range(self.V) :
            if visited[v] == False :
                temp = []
                cc.append(self.DFSUtil(temp,v,visited))
        return cc 


if __name__ == "__main__":
    g = Graph(5)
    g.addEdge(1,0)
    g.addEdge(2,3)
    g.addEdge(3,4)
    cc = g.connectedcomponents()
    print(cc)