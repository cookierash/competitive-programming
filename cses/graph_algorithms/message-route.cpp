#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
#define all(v) v.begin(),v.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
const int N = 1e5+5;
vector<int> adj[N+1];
vector<int> vis(N+1, 0);
vector<int> dis(N+1, -1), par(N+1, -1);

void bfs(int node){
    queue<int> q;
    vis[node] = true;
    dis[node] = 0;
    par[node] = -1;
    q.push(node);

    while (!q.empty()){
        node = q.front(); q.pop();
        for (int u : adj[node]){
            if (!vis[u]){
                dis[u] = dis[node] + 1;
                par[u] = node;
                vis[u] = true;
                q.push(u);
            }
        }
    }
}

void solve() {
    int n,m; cin >> n >> m;
    while (m--){
        int a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs(1);
    if (vis[n]){
        vector<int> path;
        for (int i = n; i != -1; i = par[i]) path.pb(i);
        reverse(all(path));
        cout << path.size() << nl;
        for (int x : path) cout << x << " ";
    }
    else cout << "IMPOSSIBLE";
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}