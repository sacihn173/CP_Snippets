//
// Created by Sachin on 16-07-2022.
//

#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define si set<int>
#define sll set<long long>
#define mii map<int, int>
#define mll map<long long, long long>
#define ll long long
#define llmax LONG_LONG_MAX
#define ull unsigned long long
#define imax INT_MAX
#define pb push_back
#define all(x) (x).begin(), (x).end()

/*
 * the graph should be directed Acyclic graph
 * find topological ordering using BFS (Kahn's Algorithm)
 * time = O(V + E)
 * space = O(N) + O(N)
 */

vector<int> inDegree;
vector<vector<int>> graph;
vector<int> order;

void solve() {
    int n;
    cin >> n;
    // input graph with 1-based indexing
    graph.resize(n + 1);
    inDegree.resize(n + 1, 0);
    // fill inDegree array
    for(int i = 1; i <= n; i++){
        for(int &j : graph[i]) // there is an edge from i to j
            inDegree[j]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(inDegree[i] == 0)
            q.push(i);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        order.pb(curr);
        for(int &i : graph[curr]){
            inDegree[i]--;
            if(inDegree[i] == 0)
                q.push(i);
        }
    }
    for(int &i : order)
        cout << i << " ";
    // clear all
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