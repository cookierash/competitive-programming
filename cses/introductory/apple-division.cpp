#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
const int MAX = 1e6+5;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    ll res = LLONG_MAX;
    for (int i = 0; i < (1 << n); i++){
        ll s1=0,s2=0;
        for (int j = 0; j < n; j++){
            if (i&(1 << j)){
                s1 += v[j];
            }
            else s2 += v[j];
        }
        res = min(res,abs(s1-s2));
    }
    cout << res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}