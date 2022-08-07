//
// Created by Sachin on 17-07-2022.
//

#include <bits/stdc++.h>

using namespace std;
#define ll long long

/* Cycle detection in Directed Graph
 * Maintain two visited array
 * visitedOnce stores that we have checked for this node once in a dfs
 *  --> if we have checked for a node already then we don't go to it again
 *  visited stores the path we are visiting currently, make it false while going back
 *  --> at the end of every dfs, visited is all false because we come back the whole path
 *  --> cycle exists if we reach a node back in the path that we have already visited in the
 *      current dfs
 */

vector<vector<int>> graph;
vector<bool> visitedOnce;
vector<bool> visited;
bool flag;

void dfs(int curr){
    visited[curr] = true;
    visitedOnce[curr] = true;
    for(int &i : graph[curr]){
        if(visited[curr])
            flag = true;
        else if(!visitedOnce[curr])
            dfs(i);
    }
    visited[curr] = false;
}

void solve() {
    int n;
    cin >> n;
    graph.resize(n + 1);
    visitedOnce.resize(n + 1, false);
    visited.resize(n + 1, false);
    // input graph

    for(int i = 1; i <= n; i++){
        if(!visitedOnce[i]){
            flag = false;
            dfs(i);
            if(flag)
                break;
        }
    }
    if(!flag)
        cout << "No cycle\n";
    else
        cout << "Yes cycle present\n";
    graph.clear();
    visitedOnce.clear();
    visited.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc-- > 0) solve();
    return 0;
}