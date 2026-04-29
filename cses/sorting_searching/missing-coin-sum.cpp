#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define all(v) v.begin(),v.end()
#define nl '\n'
 
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    sort(all(v));
    ll res = 1;
    for (int x : v){
        if (res < x) break;
        res += x;
    }
    cout << res;
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}