#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

/*You have an undirected, connected graph of n nodes labeled from 0 to n - 1.
 *You are given an array graph where graph[i] is a list of all the nodes connected
 *with node i by an edge.

    Return the length of the shortest path that visits every node.
    You may start and stop at any node, you may revisit nodes multiple times,
    and you may reuse edges.

State representation: Use a bitmask to track visited nodes, where each state is
(current node, visited set).
BFS for shortest path: Perform a Breadth-First Search (BFS) to explore
all possible paths in the shortest manner.
Early termination: Stop searching when all nodes have been visited,
which corresponds to the bitmask 111...1 (all bits set).
Edge cases: Handle cases where the graph is already a single node or contains cycles.
*/
struct State {
    int node, mask, cost;
};

const int nodes = 12;
int graph[nodes][nodes];
int degree[nodes];

int shortestPath(int n) {
    int fin = (1 << n) - 1;
    queue<State> q;
    unordered_set<int> visited[nodes];

    for (int i = 0; i < n; i++) {
        q.push({i, 1 << i, 0});
        visited[i].insert(1 << i);
    }

    while (!q.empty()) {
        State s = q.front();
        q.pop();

        if (s.mask == fin) {
            return s.cost;
        }
        for (int j = 0; j < degree[s.node]; j++) {
            int neighbor = graph[s.node][j];
            int newerMask = s.mask | (1 << neighbor);

            if (!visited[neighbor].count(newerMask)) {
                visited[neighbor].insert(newerMask);
                q.push({neighbor, newerMask, s.cost + 1});
            }
        }
    }
    return -1;
}

int main() {
    int n = 4;
    int tempG[nodes][nodes] = {{1,2,3}, {0,2,3}, {0,1,3}, {0,1,2}};
    int tempD[nodes] = {3,3,3,3};

    for (int i = 0; i < n; i++) {
        degree[i] = tempD[i];
        for (int j = 0; j < degree[i]; j++) {
            graph[i][j] = tempG[i][j];
        }
    }

    cout << "Output: " << shortestPath(n) << endl;

    return 0;
}
