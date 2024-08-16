from pandas import DataFrame
def dfs(graph, start, end):
    closeList = []
    openList = [[start, -1]]
    data = []
    def successor(node):
        return graph[node]
    def GT(node):
        return node == end
    while (len(openList)):
        top, prev = openList[0]
        openList.pop(0)
        closeList.append([top, prev])
        data.append([openList.copy(), top, closeList.copy(), GT(top), successor(top)])
        if(GT(top)):
            break
        
        for x in list(reversed(successor(top))):
            if x not in list(map(lambda x:x[0],closeList)) and x not in list(map(lambda x:x[0],openList)):
                openList.insert(0, [x, top])
    
    return data

def findPath(data, start, end):
    path = []
    closeListIndex = 2
    for i in range(len(data)):
        clostListTemp = data[i][closeListIndex]
        last  = clostListTemp[len(clostListTemp)-1][1]
        if(len(path) == 0):
            path.append(last)
        elif path[len(path)-1] != last:
            path.append(last)
    path.append(end)
    path.pop(0)
    return path
   


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
start = 'A'
end = 'G'
data = dfs(adjacencyList,start, end)
print(DataFrame(data, columns=["openList", "Node","closeList","GT(Node)", "Succesor(Node)"]))
path = findPath(data, start, end)
print("PATH IS ")
print(path)