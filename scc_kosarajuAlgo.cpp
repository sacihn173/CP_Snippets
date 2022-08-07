//
// Created by Sachin on 29-07-2022.
//

/*
 * finding Strongly Connected component in a Directed Graph --> Using Kosaraju's Algorithm
 * O(n) --> each node is visited only once
 */

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n;
vector<vector<int>> graph, reverseGraph;
vector<int> order;
vector<bool> visited;
vector<int> sccNumber;

void findTopoOrder(int curr){
    visited[curr] = true;
    for(int &i : reverseGraph[curr]){
        if(!visited[i])
            findTopoOrder(i);
    }
    order.push_back(curr);
}

void dfs(int curr, int comp){
    sccNumber[curr] = comp;
    visited[curr] = true;
    for(int &i : graph[curr]){
        if(!visited[i])
            dfs(i, comp);
    }
}

void solve() {
    cin >> n;
    int m; cin >> m;
    graph.resize(n + 1);
    reverseGraph.resize(n + 1);
    visited.resize(n + 1, false);
    sccNumber.resize(n + 1);
    // input graph
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        reverseGraph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i])
            findTopoOrder(i);
    }
    reverse(order.begin(), order.end());

    for(int i = 1; i <= n; i++) visited[i] = false;

    int comp = 1;
    for(int &i : order){
        if(!visited[i])
            dfs(i, comp++);
    }

    for(auto &i : sccNumber)
        cout << i << " ";
    cout << '\n';
    graph.clear();
    reverseGraph.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc-- > 0) solve();
    return 0;
}