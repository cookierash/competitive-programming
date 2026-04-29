#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define all(v) v.begin(),v.end()
#define pb push_back
#define nl '\n'

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
    int n; ll x;cin >> n >> x;
    vector<long long> a(n);
    map<long long, pair<int,int>> mp;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long need = x - a[i] - a[j];
            if (mp.count(need)) {
                auto [p, q] = mp[need];
                cout << p + 1 << " " << q + 1 << " "
                     << i + 1 << " " << j + 1;
                return;
            }
        }
        for (int j = 0; j < i; j++) {
            mp[a[i] + a[j]] = {j, i};
        }
    }
    cout << "IMPOSSIBLE";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}