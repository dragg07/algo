#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(vector<vector <int>> &graph, vector<bool> &visited, stack<int> &stk, int node){
    visited[node] = true;

    for(int i=0; i<graph[node].size(); ++i){
        int adjacent = graph[node][i];

        if(!visited[adjacent])
            dfs(graph, visited, stk, adjacent);
    }

    stk.push(node);
}

vector<int> topologicalSort(vector<vector <int>> &graph, int vertex){
    vector<bool> visited(vertex, false);
    stack<int> stk;

    for(int i=0; i<vertex; ++i){
        if(!visited[i])
            dfs(graph, visited, stk, i);
    }

    vector<int> result;
    while(!stk.empty()){
        result.push_back(stk.top());
        stk.pop();
    }

    return result;
}

int main(){
    int vertices, edges;
    cout << "Enter no. of Vertices and Edges : ";
    cin >> vertices >> edges;

    vector<vector <int>> graph(vertices);
    cout << "Enter the edges (start from 0 vertex) (u v) : ";
    for(int i=0; i<edges; ++i){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> result = topologicalSort(graph, vertices);

    cout << "\nThe Topological Sort for the following graph : " << endl;
    for(int node : result){
        cout << node << " ";
    } 

    return 0;
}
