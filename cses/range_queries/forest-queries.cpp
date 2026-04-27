#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define nl '\n'

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
    int n,q; cin >> n >> q;
    char c;
    
    vector<vector<ll>> a(n + 1, vector<ll>(n + 1, 0));
    vector<vector<ll>> pref(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j<=n; j++){
            cin >> c;
            a[i][j] = (c == '*');
            pref[i][j] = a[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }
    
    int y1,x1,y2,x2;
    while (q--){
        cin >> y1 >> x1 >> y2 >> x2;
        cout << pref[y2][x2] - pref[y2][x1-1] - pref[y1-1][x2] + pref[y1-1][x1-1] << nl;
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