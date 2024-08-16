#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

unordered_map<char, pair<int, int>> locations = {
    {'A', {1, 1}},
    {'B', {1, 4}},
    {'C', {2, 5}},
    {'D', {3, 7}},
    {'E', {3, 2}},
    {'F', {3, 5}},
    {'G', {8, 5}},
    {'I', {4, 8}},
    {'J', {6, 7}},
    {'K', {7, 3}},
    {'L', {6, 1}}
};

// Calculate Manhattan distance between two nodes
int manhattan_heuristic(char L1, char L2) {
    int x1 = locations[L1].first;
    int y1 = locations[L1].second;
    int x2 = locations[L2].first;
    int y2 = locations[L2].second;
    return abs(x1 - x2) + abs(y1 - y2);
}

// Calculate Euclidean distance between two nodes
double euclidean_distance(char point1, char point2) {
    int x1 = locations[point1].first;
    int y1 = locations[point1].second;
    int x2 = locations[point2].first;
    int y2 = locations[point2].second;
    return round(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) * 100.0) / 100.0;
}

vector<vector<char>> adjacencyList = {
    {'B', 'E'},       // A
    {'C', 'E', 'A', 'K'}, // B
    {'D', 'F'},       // C
    {'I'},            // D
    {'L'},            // E
    {'J', 'K'},       // F
    {},               // G (no connections)
    {'J'},            // I
    {'G'},            // J
    {'K'},            // L
    {'G'}             // K
};

// Struct to represent a node in the priority queue
struct Node {
    char name;
    int h_value;
    char prev;
    
    bool operator<(const Node &other) const {
        return h_value > other.h_value;  // Min-heap based on h_value
    }
};

// Best-First Search algorithm
vector<vector<char>> best_first_search(vector<vector<char>> &graph, char start, char end) {
    vector<vector<char>> closeList;
    priority_queue<Node> openList;
    openList.push({start, manhattan_heuristic(start, end), -1});

    while (!openList.empty()) {
        Node top = openList.top();
        openList.pop();

        bool found = false;
        for (auto &node : closeList) {
            if (node[0] == top.name) {
                found = true;
                break;
            }
        }
        if (found) continue;

        closeList.push_back({top.name, top.h_value, top.prev});

        if (top.name == end) break;

        for (char node : graph[top.name - 'A']) {
            bool found_in_close = false;
            for (auto &n : closeList) {
                if (n[0] == node) {
                    found_in_close = true;
                    break;
                }
            }
            if (!found_in_close) {
                openList.push({node, manhattan_heuristic(node, end), top.name});
            }
        }
    }
    return closeList;
}

// Find the path from start to end
vector<char> findPath(vector<vector<char>> &closeList, char start, char end) {
    vector<char> path;
    char node = end;
    double total_distance = 0;

    while (node != start) {
        for (auto &n : closeList) {
            if (n[0] == node) {
                path.push_back(n[0]);
                if (n[2] != -1) {
                    total_distance += euclidean_distance(n[2], n[0]);
                }
                node = n[2];
                break;
            }
        }
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    cout << "Total Euclidean distance: " << total_distance << endl;
    return path;
}

int main() {
    char start = 'A';
    char end = 'G';

    vector<vector<char>> closeList = best_first_search(adjacencyList, start, end);
    
    vector<char> path = findPath(closeList, start, end);
    
    cout << "PATH IS: ";
    for (char node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
