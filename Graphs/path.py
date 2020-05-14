from collections import defaultdict


class Graph :
    def __init__(self,vertices) :
        self.V = vertices
        self.graph = defaultdict(list)


    def addedge(self,u,v) :
        self.graph[u].append(v)

    
    def isreachable(self,src,dst) :
        visited = [False] * self.V
        queue = []

        queue.append(src)
        visited[src] = True 
        while queue :
            n = queue.pop(0)
            if n == dst :
                return True 
            
            for i in self.graph[n] :
                if visited[i] == False :
                    queue.append(i)
                    visited[i] =True 

        return False 


if __name__ == "__main__":
    g = Graph(4)
    g.addedge(0,1)
    g.addedge(1,2)
    g.addedge(2,0)
    g.addedge(0,2)
    g.addedge(2,3)
    g.addedge(3,3)

    u = 1;v = 3
    print(g.isreachable(u,v),g.isreachable(v,u))

