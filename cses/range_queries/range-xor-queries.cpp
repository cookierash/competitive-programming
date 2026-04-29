#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define nl '\n'
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int MAX = 2e5;
ll a[MAX+5], t[4*MAX+5], n, q;

void build(int node, int tl, int tr){
    if (tl == tr){
        t[node] = a[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build(node*2, tl, tm);
    build(node*2+1, tm+1, tr);
    t[node] = (t[node*2]^t[node*2+1]);
}

ll query (int node, int tl, int tr, int l, int r){
    if (l > tr || r < tl) return 0;
    if (l <= tl && r >= tr) return t[node];

    int tm = (tl+tr)/2;
    return (query(2*node, tl, tm, l, min(tm, r))^query(2*node+1, tm+1, tr, max(l,tm+1), r));
}

void solve() {
    cin >> n >>q;
    for (int i = 1; i<=n; i++) cin >> a[i];
    build(1,1,n);

    while(q--){
        int a,b;
        cin >> a >> b;
        cout << query(1,1,n,a,b) << nl;
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