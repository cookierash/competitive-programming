#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define nl '\n'
 
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
void solve() {
    int n,q,a,b; cin >> n >> q;
    vector<ll> v(n+1);
    ll pref[n+1]; pref[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
    }
 
    while (q--){
        cin >> a >> b;
        cout << pref[b] - pref[a-1] << nl;
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