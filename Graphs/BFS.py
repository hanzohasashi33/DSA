from collections import defaultdict


class Graph :
    def __init__(self) :
        self.graph = defaultdict(list)

    def addedge(self,u,v) :
        self.graph[u].append(v)

    
    def BFS(self,s) :
        distance = [float("inf")] * len(self.graph)
        visited = [False] * len(self.graph)
        previous = [None] * len(self.graph)
        queue = []
        bfs = []

        queue.append(s)
        visited[s] = True
        distance[s] = 0

        while queue :
            s = queue.pop(0)
            bfs.append(s)

            for i in self.graph[s] :
                if visited[i] == False :
                    queue.append(i)
                    visited[i] = True 
                    distance[i] = distance[s] + 1
                    previous[i] = s
        return previous,bfs

        


    def printgraph(self) :
        for i in self.graph :
            print(i,self.graph[i])


    def reconstructpath(self,s,u,previous,bfs) :
        result = []
        while u != s :
            result.append(u)
            u = previous[u]
        result.reverse()
        print(result)




if __name__ == "__main__" :
    g = Graph() 
    g.addedge(0, 1) 
    g.addedge(0, 2) 
    g.addedge(1, 2) 
    g.addedge(2, 0) 
    g.addedge(2, 3) 
    g.addedge(3, 3) 
    g.printgraph()
    print ("Following is Breadth First Traversal" " (starting from vertex {})".format("2")) 
    previous,bfs = g.BFS(2)
    print(bfs) 
    print(previous)
    g.reconstructpath(2,1,previous,bfs)
