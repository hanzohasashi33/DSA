from collections import defaultdict

class Graph() :
    def __init__(self,V) :
        self.V = V
        self.graph =  defaultdict(list)


    def addedge(self,v,w) :
        self.graph[v].append(w)
        self.graph[w].append(v)


    def isCyclicUtil(self,v,visited,parent) :
        visited[v] = True 

        for i in self.graph[v] :
            if visited[i] == False :
                if self.isCyclicUtil(i,visited,v) :
                    return True
            
            elif parent != i :
                return True 
        return False 


    def isCyclic(self) :
        visited = [False] * self.V 

        for i in range(self.V) :
            if visited[i] == False :
                if self.isCyclicUtil(i,visited,-1) == True :
                    return True 
        
        return False 

    def printgraph(self) :
        for i in (self.graph) :
            print(i,"->",self.graph[i])

if __name__ == "__main__":
    g = Graph(5) 
    g.addedge(1,0)
    g.addedge(0,2)
    g.addedge(2,0)
    g.addedge(0,3)
    g.addedge(3,4)

    g.printgraph()
    print(g.isCyclic())


    g1 = Graph(3)
    g1.addedge(0,1)
    g1.addedge(1,2)
    g1.printgraph()
    print(g1.isCyclic())
    