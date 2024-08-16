from pandas import DataFrame
def bfs(graph, start, end):
    closeList = []
    start = 'A'
    end = 'G'
    openList = [start]
    data = []
    def successor(node):
        return graph[node]
    def GT(node):
        return node == end
    done = False
    while (len(openList) and not done):

        top = openList[0]
        data.append([openList.copy(), top, closeList.copy(), GT(top), successor(top)])
        for i in range(len(openList)):
            top = openList[0]
            openList.pop(0)
            closeList.append(top)
            if(GT(top)):
                done = True
                break
            for x in list(reversed(successor(top))):
                if x not in closeList and x not in openList:
                    openList.append(x)
        
    print(DataFrame(data, columns=["openList", "Node","closeList","GT(Node)", "Succesor(Node)"]))
    
adjacencyList = {
    'A': ['B', 'D'],
    'B': ['C','E','A'],
    'C': ['B'],
    'D': ['A', 'E', 'I', 'H'],
    'E': ['B', 'F', 'I', 'D'],
    'F': ['G', 'E'],
    'H':['D', 'I'],
    'I':['E','G','H', 'D'],
    'G': ['F', 'I', 'E'],

}
bfs(adjacencyList, 'A', 'G')