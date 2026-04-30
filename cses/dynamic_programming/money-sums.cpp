#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define nl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
#define ll long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int MAX = 2e5;

void solve(){
    int n,mx=0; cin >> n;
    vector<int> coins(n);
    for (int &x : coins){
        cin >> x;
        mx+=x;
    }
    vector<bool> dp(mx+1, false);
    dp[0] = true;
    
    for (int c : coins){
        for (int i = mx; i>=c; i--){
            if (dp[i-c]) dp[i] = true;
        }
    }
    int cnt = 0;
    for (int i = 1; i<=mx; i++){
        if (dp[i]) cnt++;
    }
    cout << cnt << nl;
    for (int i = 1; i<=mx; i++){
        if (dp[i]) cout << i << " ";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
}