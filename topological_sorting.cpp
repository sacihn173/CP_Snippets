//
// Created by Sachin on 11-07-2022.
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> visited;
// the graph should be directed acyclic graph
// reverse of order will be correct topological sorting
vector<int> order;

void dfs(int curr, int par){
    visited[curr] = true;
    for(int &i : graph[curr]){
        if(!visited[i])
            dfs(i, curr);
    }

    // I come here after visiting all the subtrees of curr
    order.push_back(curr);
}

void solve() {
    // zeros based indexing
    visited.resize(n);
    for(int i = 0; i < n; i++)
        dfs(i, -1);

    reverse(order.begin(), order.end());

    visited.clear();
    order.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    while(tc-- > 0) solve();
    return 0;
}

