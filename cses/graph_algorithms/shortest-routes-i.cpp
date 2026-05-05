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
vector<pair<int,int>> adj[N+1];
vector<int> vis(N+1, 0);
vector<ll> dis(N+1, LLONG_MAX), par(N+1, INT_MAX);

void dijkstra(int node){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    dis[node] = 0;
    q.push({0, node});

    while (!q.empty()){
        auto [w, v] = q.top(); q.pop();

        if (vis[v]) continue;
        vis[v] = 1;

        for (auto [u,d] : adj[v]){
            if (dis[u] > dis[v] + d){
                dis[u] = dis[v] + d;
                q.push({dis[u], u});
            }
        }
    }
}

void solve() {
    int n,m; cin >> n >> m;
    while (m--){
        int a,b, c; cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    dijkstra(1);
    for (int i = 1; i<=n; i++){
        cout << dis[i] << " ";
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