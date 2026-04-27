#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
const int MAX = 1e6+5;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
    int n,m,k; cin >> n >> m >> k;
    char a[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j <m; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int y = 0; y < k; y++){
        for (int j = 0; j < m; j++){
            for (int x = 0; x < k; x++) cout << a[i][j];
        }
        cout << nl;
        }

    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}