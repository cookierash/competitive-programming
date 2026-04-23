#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define nl '\n'

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
    ll n,x; cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    ll sum = 0, ans = 0;
    int l = 0;

    for (int r = 0; r<n; r++){
        sum += v[r];
        while (sum > x){
            sum -= v[l];
            l++;
        }
        if (sum == x) ans++;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}