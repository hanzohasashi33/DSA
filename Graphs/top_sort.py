from collections import defaultdict


class Graph : 
    def __init__(self,vertices) :
        self.graph = defaultdict(list)
        self.V = vertices


    def addEdge(self,u,v) :
        self.graph[u].append(v)

    
    def TopsortUtil(self,v,visited,stack) :
        visited[v] = True 

        for i in self.graph[v] :
            if visited[i] == False :
                self.TopsortUtil(i,visited,stack)
        
        stack.insert(0,v)

    def TopSort(self) :
        visited = [False] * self.V 
        stack = []

        for i in range(self.V) :
            if visited[i] == False :
                self.TopsortUtil(i,visited,stack)
        print(stack)


if __name__ == "__main__":
    g = Graph(6)
    g.addEdge(5,2)
    g.addEdge(5,0)
    g.addEdge(4,0)
    g.addEdge(4,1)
    g.addEdge(2,3)
    g.addEdge(3,1)
    g.TopSort()