#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define all(v) v.begin(),v.end()
#define pb push_back
#define nl '\n'
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int mod = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> dp(n+1);
    dp[0] = 1;

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=6; j++){
            if (i-j>=0){
                (dp[i] += dp[i-j]) %= mod;
            }
        }
    }
    
    cout << dp[n];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}