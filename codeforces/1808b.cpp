#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
#define all(v) v.begin(),v.end()
const int MAX = 1e6+5;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
    int t; cin >> t;
    while (t--){
        int n,m; cin >> n >> m;
        vector<vector<ll>> v(n, vector<ll>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) cin >> v[i][j];
        }
        ll res = 0;

        for (int col = 0; col < m; col++){
             vector<ll> a;

            for (int row = 0; row < n; row++){
                a.push_back(v[row][col]);
            }
            sort(all(a));

            ll pref = 0;
            for (int i = 0; i < n; i++){
                res += a[i] * i - pref;
                pref += a[i];
            }
        }
        cout << res << nl;
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