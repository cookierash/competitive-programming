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
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    
    int l = 0, ans = 0;

    for (int r = 0; r < n; r++){
        while(d[r] - d[l] > k){
            l++;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}