#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define nl '\n'

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
    int n,a,b; cin >> n;
    vector<pair<int,int>> v;
    while(n--){
        cin >> a >> b;
        v.push_back({a,+1});
        v.push_back({b,-1});
    }
    sort(v.begin(), v.end());
    
    int cur = 0, ans = 0;
    for (auto [time, change] : v){
        cur += change;
        ans = max(ans, cur);
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