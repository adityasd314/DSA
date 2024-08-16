from pandas import DataFrame, set_option
from heapq import *
from math import sqrt

locations = {
    'A': (1, 1),
    'B': (1, 4),
    'C': (2, 5),
    'D': (3, 7),
    'E': (3, 2),
    'F': (3, 5),
    'G': (8, 5),
    'I': (4, 8),
    'J': (6, 7),
    'K': (7, 3),
    'L': (6, 1)
}


def manhattan_heuristic(L1, L2):
    x1, y1 = locations[L1]
    x2, y2 = locations[L2]
    return abs(x1 - x2) + abs(y1 - y2)

def euclidean_distance(point1, point2):
    x1, y1 = locations[point1]
    x2, y2 = locations[point2]
    return round(sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2), 2)

def best_first_search(graph, start, end):
    closeList = []
    openList = [[manhattan_heuristic(start, end), start, -1]]
    heapify(openList)
    data = []

    def successor(node):
        return graph[node]

    def GT(node):
        return node == end

    while openList:
        h, top, prev = heappop(openList)

        if any(top == node for node, _, _ in closeList):
            continue

        closeList.append([top, h, prev])
        data.append([openList.copy(), top, closeList.copy(),
                    GT(top), successor(top)])

        if GT(top):
            break

        for node in successor(top):
            if not any(node == c_node for c_node, _, _ in closeList):
                heappush(openList, [manhattan_heuristic(node, end), node, top])

    return data




def findPath(data, start, end):
    closeList = data[-1][2]
    path = []
    node = end
    total_distance = 0

    while node != start:
        for n, wt, prev in closeList:
            if n == node:
                path.append(n)
                if prev != -1:
                    total_distance += euclidean_distance(prev, n)
                node = prev
                break
    path.append(start)
    path.reverse()

    print("Total Euclidean distance: ", total_distance)
    return path


adjacencyList = {
    'A': ['B', 'E'],
    'B': ['C', 'E', 'A','K'],
    'C': ['D','F'],
    'D': ['I'],
    'E': ['L'],
    'F': ['J', 'K'],
    'I': ['J'],
    'J': ['G'],
    'L':['K'],
    'K':['G'],
    'G':[]
}

start = 'A'
end = 'G'
data = best_first_search(adjacencyList, start, end)
df = DataFrame(data, columns=["openList", "Node",
               "closeList", "GT(Node)", "Successor(Node)"])

print(df)
path = findPath(data, start, end)
print("PATH IS")
print(path)
