#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
#define all(v) v.begin(),v.end()
const int MAX = 1e6+5;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int N = 150;
vector<int> adj[N+1];
vector<bool> vis(N+1, false);

void dfs(int node){
    if (vis[node]) return;
    vis[node] = true;
    
    for (auto u : adj[node]){
        if (!vis[u]){
            dfs(u);
        }
    }
}

void solve() {
    int n,m; cin >> n >> m;
    int a,b;
    while(m--){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int,int>> roads;
    int last = -1;
    for (int i = 1; i<=n; i++){
        if (!vis[i]){
            if (last != -1){
                roads.push_back({last,i});
            }
            dfs(i);
            last = i;
        }
    }
    cout << roads.size() << nl;
    for (auto [s, f] : roads){
        cout << s<< " " << f << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}