#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define nl '\n'

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
    ll n,m,k,l,r,d,a,b; cin >> n >> m >> k;
    vector<int> v(n+1);
    vector<tuple<int,int,int>> ops(m+1);
    for (int i = 1; i<=n; i++) cin >> v[i];
    vector<int> diff(n+2);
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}