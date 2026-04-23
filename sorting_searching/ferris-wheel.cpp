#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define nl '\n'

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
    int n,x,res=0; cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int L = 0, R = n-1;
    while (L<=R){
        if (v[R] + v[L] <= x){
            res++;
            R--;
            L++;
        }
        else{
            res++;
            R--;
        }
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