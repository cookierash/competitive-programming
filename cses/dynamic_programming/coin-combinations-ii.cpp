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
    int n, s; cin >> n >> s;
    vector<int> coins(n), dp(s+1, 0);
    for (int &x : coins) cin >> x;
    dp[0] = 1;

    for (int c : coins){
        for (int i = 1; i<=s; i++){
            if (i-c>=0){
                (dp[i] += dp[i-c]) %= mod;
            }
        }
    }
    cout << dp[s];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}