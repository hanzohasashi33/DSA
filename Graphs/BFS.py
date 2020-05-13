from collections import defaultdict


class Graph :
    def __init__(self) :
        self.graph = defaultdict(list)

    def addedge(self,u,v) :
        self.graph[u].append(v)

    
    def BFS(self,s) :
        visited = [False] * len(self.graph)
        queue = []

        queue.append(s)
        visited[s] = True

        while queue :
            s = queue.pop(0)
            print(s,end = " ")

            for i in self.graph[s] :
                if visited[i] == False :
                    queue.append(i)
                    visited[i] = True 


if __name__ == "__main__" :
    g = Graph() 
    g.addedge(0, 1) 
    g.addedge(0, 2) 
    g.addedge(1, 2) 
    g.addedge(2, 0) 
    g.addedge(2, 3) 
    g.addedge(3, 3) 
  
    print ("Following is Breadth First Traversal" " (starting from vertex {})".format("2")) 
    g.BFS(2) 
