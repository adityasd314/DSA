from heapq import *

def ucs(graph, start, end):
    closeList = []
    openList = [[0, start, -1]]
    heapify(openList)
    data = []

    def successor(node):
        return graph[node]

    def GT(node):
        return node == end

    while openList:
        wt, top, prev = heappop(openList)
        
        if any(top == node for node, _, _ in closeList):
            continue
        
        closeList.append([top, wt, prev])
        data.append({
            "openList": openList.copy(),
            "Node": top,
            "closeList": closeList.copy(),
            "GT(Node)": GT(top),
            "Successor(Node)": successor(top)
        })
        
        if GT(top):
            break
        
        for x in successor(top):
            node, cost = x
            if not any(node == c_node for c_node, _, _ in closeList):
                heappush(openList, [wt + cost, node, top])
    
    return data

def findPath(data, start, end):
    closeList = data[-1]["closeList"]
    path = []
    node = end
    sum = closeList[-1][1]
    while node != start:
        for n, wt, prev in closeList:
            if n == node:
                path.append(n)
                node = prev
                break
    path.append(start)
    path.reverse()
    print("Sum:", sum)
    return path

adjacencyList = {
    'A': [('B', 4), ('D', 1)],
    'B': [('C', 5), ('E', 3), ('A', 4)],
    'C': [('B', 5)],
    'D': [('A', 1), ('E', 2), ('I', 3), ('H', 4)],
    'E': [('B', 3), ('F', 3), ('I', 1), ('D', 2)],
    'F': [('G', 5), ('E', 3)],
    'H': [('D', 4)],
    'I': [('E', 1), ('G', 2), ('D', 3)],
    'G': [('F', 5), ('I', 2)],
}

start = 'A'
end = 'G'
data = ucs(adjacencyList, start, end)

for entry in data:
    print(f"Open List: {entry['openList']}")
    print(f"Current Node: {entry['Node']}")
    print(f"Closed List: {entry['closeList']}")
    print(f"Goal Test: {entry['GT(Node)']}")
    print(f"Successors: {entry['Successor(Node)']}")
    print("------------")

path = findPath(data, start, end)
print("PATH IS")
print(path)
