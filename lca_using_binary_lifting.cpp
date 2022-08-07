//
// Created by Sachin on 22-06-2022.
//
#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define vll vector<long long>
#define ll long long
#define ull unsigned long long
#define llmax LONG_LONG_MAX
#define imax INT_MAX
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 1;
vector<int> graph[N];
vi lvl(N, -1);
const int M = (int)log2(N);
// take M as log2(N) + 1
vector<vector<int>> par(N, vi(M));

void dfs(int curr, int parent){
    lvl[curr] = lvl[parent] + 1;
    par[curr][0] = parent;
    for(int i = 1; i < M; i++){
        par[curr][i] = par[par[curr][i - 1]][i - 1];
    }
    for(int &i : graph[curr]){
        if(i != parent){
            dfs(i, curr);
        }
    }
}

/*
 * lca using binary lifting
 * time - O(n * log(n)) for the dfs and parent matrix filling
 * and O(log(n)) for each lca finding query
 */

int lca(int node1, int node2){
    if(node1 == node2) return node2;
    // lvl of node1 is always more
    if(lvl[node1] < lvl[node2]) swap(node1, node2);
    int diff = lvl[node1] - lvl[node2];
    for(int i = M - 1; i >= 0; i--){
        if((diff >> i) & 1){
            node1 = par[node1][i];
        }
    }
    // now node1 and node2 are at same lvl
    for(int i = M - 1; i >= 0; i--){
        if(par[node1][i] != par[node2][i]){
            node1 = par[node1][i];
            node2 = par[node2][i];
        }
    }
    if(node1 == node2) return node1;
    return par[node1][0];
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1, 0);

    cout << lca(11, 10) << endl;
    cout << lca(8, 9) << endl;
    cout << lca(4, 3) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
//    cin >> tc;
    while (tc-- > 0) solve();
    return 0;
}
