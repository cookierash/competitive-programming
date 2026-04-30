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
    int n,s; cin >> n >> s;
    vector<ll> v(n);
    for (ll &x : v) cin >> x;
 
    vector<ll> s1,s2;
    int n1 = n/2;
    int n2 = n-n1;
    for (int i = 0; i < (1 << n1); i++){
        ll sum = 0;
        for (int j = 0; j < n1; j++){
            if (i&(1 << j)){
                sum += v[j];
            }
        }
        s1.pb(sum);
    }
    for (int i = 0; i < (1 << n2); i++){
        ll sum = 0;
        for (int j = 0; j < n2; j++){
            if (i&(1 << j)){
                sum += v[n1+j];
            }
        }
        s2.pb(sum);
    }    
    sort(all(s2));
    ll ans = 0;
    for (ll x : s1){
        ans += upper_bound(all(s2), s-x) - lower_bound(all(s2), s-x);
    }
    cout << ans;
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