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
#define imax INT_MAX
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define _print(x) for(int &i : (x)) cout << i << ' ';
 
struct fenwick{
    int n;
    vll fn;
    void init(int n){
        this->n = n + 1;
        fn.resize(this->n, 0);
    }
    void add(int index, int element){
        for(index++; index < n; index += (index & (-index))) fn[index] += element;
    }
    ll query(int i){
        i++;
        ll ans = 0;
        for(i; i > 0; i -= (i & (-i))) ans += fn[i];
        return ans;
    }
    ll query(int l, int r){
        return query(r) - query(l - 1);
    }
};

void solve(){
    
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    while(tc-- > 0) solve();
    return 0;
}