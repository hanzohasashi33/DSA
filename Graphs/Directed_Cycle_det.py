from collections import defaultdict

class Graph() :
    def __init__(self,vertices) :
        self.graph = defaultdict(list)
        self.V = vertices


    def addedge(self,u,v) :
        self.graph[u].append(v)

        
    def isCyclicutil(self,v,visited,recstack) :
        visited[v] = True 
        recstack[v] = True 

        for neighbour in self.graph[v] :
            if visited[neighbour] == False :
                if self.isCyclicutil(neighbour,visited,recstack) == True :
                    return True 
            elif recstack[neighbour] == True :
                return True 

        recstack[v] = False
        return False 


    def iscyclic(self) :
        visited = [False] * self.V 
        recstack = [False] * self.V 
        for node in range(self.V) :
            if visited[node] == False :
                if self.isCyclicutil(node,visited,recstack) == True :
                    return True
        return False 

    def print_graph(self) :
        for i in self.graph :
            print(i,self.graph[i])

if __name__ == "__main__":
    g = Graph(4)
    g.addedge(0,1)
    g.addedge(0,2)
    g.addedge(1,2)
    g.addedge(2,0)
    g.addedge(2,3)
    g.addedge(3,3)

    print(g.iscyclic())
    g.print_graph()