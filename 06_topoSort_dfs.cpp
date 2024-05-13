#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//DFS traversal
void dfs(vector<vector<int>>& graph, vector<bool>& visited, stack<int>& stk, int node) {
    visited[node] = true;

    // Traverse all adjacent nodes
    for (int i = 0; i < graph[node].size(); ++i) {
        int adjacent = graph[node][i];
        if (!visited[adjacent]) {
            dfs(graph, visited, stk, adjacent);
        }
    }
    stk.push(node);
}

//topological sorting
vector<int> topologicalSort(vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false);
    stack<int> stk;

    // Perform DFS traversal for each unvisited node
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(graph, visited, stk, i);
        }
    }
    vector<int> result;
    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }
    return result;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<int> result = topologicalSort(graph, n);

    cout << "Topological Sorting: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
