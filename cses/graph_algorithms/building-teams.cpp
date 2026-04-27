#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
#define all(v) v.begin(),v.end()
const int MAX = 1e6+5;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
const int N = 1e5+5;
vector<int> adj[N+1];
vector<int> vis(N+1, 0);
bool flag = true;
 
void dfs(int node, int color){
    if (vis[node]) return;
    vis[node] = color;
    
    for (auto u : adj[node]){
        if (vis[u] == color){
            flag = false;
            return;
        }
        if (!vis[u]){
            if (color == 1) dfs(u,2);
            else dfs(u,1);
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
 
    for (int i = 1; i<=n; i++){
        if (!vis[i]){
            dfs(i, 1);
        }
    }
 
    if (!flag){
        cout << "IMPOSSIBLE"; return;
    }
    for (int i = 1; i<=n; i++){
        cout << vis[i] << " ";
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