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
    int n,m,q; cin >> n >> m >> q;
    while (m--){
        int a,b, c; cin >> a >> b >> c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        dis = vector<ll>(N+1,LLONG_MAX);
        vis = vector<int>(N+1,0);
        dijkstra(a);
        if (dis[b] != LLONG_MAX) cout << dis[b];
        else cout << -1;
        cout << nl;
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