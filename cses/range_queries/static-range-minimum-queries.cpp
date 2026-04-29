#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int N = 2e5;

ll t[4*N+5], a[N+5], n, q;

void build (int v, int tl, int tr){
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    
    int tm = (tl+tr)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = min(t[2*v], t[2*v+1]);
}

ll query (int v, int tl, int tr, int l, int r){
    if (tr < l || tl > r) return LLONG_MAX;
    if (tl >= l && tr <= r) return t[v];

    int tm = (tl+tr)/2;
    return min(query(2*v, tl, tm, l, min(r,tm)), query(2*v+1, tm+1, tr, max(l,tm), r));
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i<=n; i++) cin >> a[i];
    build(1, 1, n);
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