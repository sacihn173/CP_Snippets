//
// Created by Sachin on 01-08-2022.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph; // node, weight

void solve() {
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int source;
    cin >> source;

    // minimum distance of ith node from source node
    vector<int> distances(n + 1, INT_MAX);
    // distance of this node from source, node
    set<pair<int, int>> s;
    s.insert({0, source});
    distances[source] = 0;

    while(!s.empty()){
        int currNode = s.begin()->second, weightTillNow = s.begin()->first;
        s.erase(s.begin());

        for(auto &i : graph[currNode]){
            int nbrNode = i.first, nodeWeight = i.second;
            if(weightTillNow + nodeWeight < distances[nbrNode]){

                // erase if this node already in set with some weight
                auto it = s.find({distances[nbrNode], nbrNode});
                if(it != s.end())
                    s.erase(it);

                distances[nbrNode] = weightTillNow + nodeWeight;

                // push back into the set with new distance from source
                s.insert({distances[nbrNode], nbrNode});

            }
        }
    }

    for(int i : distances) cout << i << " ";
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