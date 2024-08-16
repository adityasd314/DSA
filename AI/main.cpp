#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

// Define the adjacency list type
using AdjacencyList = std::unordered_map<char, std::vector<char>>;

// Define the data structure to store the state of the search
struct State {
    std::vector<std::pair<char, char>> openList;
    char node;
    std::vector<std::pair<char, char>> closeList;
    bool GT;
    std::vector<char> successor;
};

// Function to perform the depth-first search (DFS)
std::vector<State> dfs(const AdjacencyList& graph, char start, char end) {
    std::vector<std::pair<char, char>> closeList;
    std::vector<std::pair<char, char>> openList = {{start, -1}};
    std::vector<State> data;

    auto successor = [&](char node) {
        return graph.at(node);
    };

    auto GT = [&](char node) {
        return node == end;
    };

    while (!openList.empty()) {
        auto [top, prev] = openList.front();
        openList.erase(openList.begin());
        closeList.push_back({top, prev});
        data.push_back({openList, top, closeList, GT(top), successor(top)});

        if (GT(top)) {
            break;
        }

        for (auto it = successor(top).rbegin(); it != successor(top).rend(); ++it) {
            char x = *it;
            auto inCloseList = std::find_if(closeList.begin(), closeList.end(), [&](const auto& p) { return p.first == x; });
            auto inOpenList = std::find_if(openList.begin(), openList.end(), [&](const auto& p) { return p.first == x; });
            if (inCloseList == closeList.end() && inOpenList == openList.end()) {
                openList.insert(openList.begin(), {x, top});
            }
        }
    }

    return data;
}

// Function to find the path from the DFS data
std::vector<char> findPath(const std::vector<State>& data, char start, char end) {
    std::vector<char> path;
    const int closeListIndex = 2;

    for (const auto& state : data) {
        const auto& closeListTemp = state.closeList;
        char last = closeListTemp.back().second;

        if (path.empty()) {
            path.push_back(last);
        } else if (path.back() != last) {
            path.push_back(last);
        }
    }

    path.push_back(end);
    path.erase(path.begin());

    return path;
}

int main() {
    AdjacencyList adjacencyList = {
        {'A', {'B', 'D'}},
        {'B', {'C', 'E', 'A'}},
        {'C', {'B'}},
        {'D', {'A', 'E', 'I', 'H'}},
        {'E', {'B', 'F', 'I', 'D'}},
        {'F', {'G', 'E'}},
        {'H', {'D', 'I'}},
        {'I', {'E', 'G', 'H', 'D'}},
        {'G', {'F', 'I', 'E'}}
    };

    char start = 'A';
    char end = 'G';

    auto data = dfs(adjacencyList, start, end);

    // Display the data in a tabular format
    std::cout << "openList\tNode\tcloseList\tGT(Node)\tSuccessor(Node)" << std::endl;
    for (const auto& state : data) {
        std::cout << "{ ";
        for (const auto& p : state.openList) std::cout << "(" << p.first << ", " << p.second << ") ";
        std::cout << "}\t" << state.node << "\t{ ";
        for (const auto& p : state.closeList) std::cout << "(" << p.first << ", " << p.second << ") ";
        std::cout << "}\t" << state.GT << "\t{ ";
        for (const auto& s : state.successor) std::cout << s << " ";
        std::cout << "}" << std::endl;
    }

    auto path = findPath(data, start, end);
    std::cout << "PATH IS " << std::endl;
    for (char node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}
