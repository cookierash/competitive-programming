#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
const int MAX = 1e6+5;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
    int x,y,m; cin >> x >> y >> m;
    int ans = 0;

    for (int i = 0; i*x <= m; i++){
        for (int j = 0; j*y + i*x <=m; j++){
            ans = max(ans, i*x + j*y);
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}