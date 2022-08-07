//
// Created by Sachin on 17-07-2022.
//

#include <bits/stdc++.h>

using namespace std;
#define ll long long

/* Cycle detection in Directed Graph
 * Using Kahn's Algorithm (for finding topological order)
 * --> if the size of topological order formed is n then no cycle
 * --> if there is a cycle then the inDegree of new nodes become negative and they are not pushed again
 *   into the queue
 */

vector<vector<int>> graph;
vector<int> inDegree; // number of edges coming to i
vector<int> order;

void solve() {
    int n;
    cin >> n;
    graph.resize(n + 1);
    inDegree.resize(n + 1, 0);
    // input graph

    for(int i = 1; i <= n; i++){
        for(int &j : graph[i])
            inDegree[j]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(inDegree[i] == 0)
            q.push(i);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        order.push_back(curr);
        for(int &i : graph[curr]){
            inDegree[i]--;
            if(inDegree[i] == 0)
                q.push(i);
        }
    }

    if(order.size() != n)
        cout << "Cycle present!";
    else
        cout << "No cycle present!";

    graph.clear();
    inDegree.clear();
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