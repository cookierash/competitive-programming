#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
#define all(v) v.begin(),v.end()
const int MAX = 1e6+5;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
void solve() {
    int n; cin >> n;
    vector<int> a(2*n);
    for (int i = 0; i < 2*n; i++) cin >> a[i];
    sort(all(a));
 
    int ans = INT_MAX;
 
    for (int i = 0; i < 2*n; i++){
        for (int j = i+1; j < 2*n; j++){
            vector<int> b;
            for (int k = 0; k < 2*n; k++){
                if (i != k && j != k){
                    b.push_back(a[k]);
                }
            }
 
            int cost = 0;
            for (int k = 0; k < b.size(); k+=2){
                cost += b[k+1] - b[k];
            }
            ans = min(ans, cost);
        }
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