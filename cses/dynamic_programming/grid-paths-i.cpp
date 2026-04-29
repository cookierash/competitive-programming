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
    char grid[n+1][n+1];
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));

    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            cin >> grid[i][j];
            if ((j == 1 || i == 1) && grid[i][j] != '*') dp[i][j] = 1;
        }
    }
    
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            if (i == j && j == 1) continue;

            if (i > 1 && j > 1 && grid[i][j] != '*'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            }
            else if (i > 1 && grid[i][j] != '*') dp[i][j] = (dp[i-1][j])%mod;
            else if (j > 1 && grid[i][j] != '*') dp[i][j] = (dp[i][j-1])%mod;
        }
    }
    
    cout << dp[n][n];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}