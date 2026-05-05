#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define nl '\n'
#define pb push_back
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int MAXN = 2e5+5;
ll n,q, v[MAXN], t[4*MAXN], lazy[4*MAXN];

void build(int node, int tl, int tr){
    if (tl == tr){
        t[node] = v[tl];
        return;
    }
    int tm = (tl+tr)/2;
    build(2*node, tl, tm);
    build(2*node+1, tm+1, tr);
    t[node] = t[node*2] + t[node*2+1];
}

void apply(int node, int tl, int tr, ll val){
    t[node] += (tr - tl + 1) * val;
    lazy[node] += val;
}

void push(int node, int tl, int tr){
    if (lazy[node] == 0 || tl == tr) return;
    int tm = (tl+tr)/2;
    
    apply(node*2, tl, tm, lazy[node]);
    apply(node*2+1, tm+1, tr, lazy[node]);

    lazy[node] = 0;
}

void update(int node, int tl, int tr, int l, int r, ll val){
    if (l > r) return;

    if (l == tl && r == tr){
        apply(node, tl, tr, val);
        return;
    }
    push(node, tl, tr);

    int tm = (tl+tr)/2;
    update(node*2, tl, tm, l, min(tm, r), val);
    update(node*2+1, tm+1, tr, max(l, tm+1), r, val);
    t[node] = t[node*2] + t[node*2+1];
}

ll query(int node, int tl, int tr, int l, int r){
    if (l > r) return 0;
    if (l == tl && r == tr){
        return t[node];
    }
    push(node, tl, tr);

    int tm = (tl+tr)/2;
    return query(node*2, tl, tm, l, min(tm, r)) + query(node*2+1, tm+1, tr, max(l, tm+1), r);
}


void solve() {
    cin >> n >> q;
    for (int i = 1 ; i<=n; i++) cin >> v[i];
    build(1,1,n);
    while(q--){
        int num; cin >> num;
        if (num == 1){
            int a,b,u; cin >> a >> b >> u;
            update(1,1,n,a,b,u);
        }
        else{
            int k; cin >> k;
            cout << query(1,1,n,k,k) << nl;
        }
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