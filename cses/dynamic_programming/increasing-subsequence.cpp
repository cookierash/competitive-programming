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
    int n; cin >> n;
    vector<ll> v(n+1), dp(n+1,1);
    for (int i = 1; i<=n; i++) cin >> v[i];

    dp[0] = 0;
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<i; j++){
            if (v[j] < v[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
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