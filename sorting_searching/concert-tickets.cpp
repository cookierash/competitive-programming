#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define nl '\n'

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
    int n,m,k; cin >> n >> m;
    multiset<int> ms;
    vector<int> t(m);
    for (int i = 0; i < n; i++){
        cin >> k;
        ms.insert(k);
    }
    for (int i = 0; i < m; i++) cin >> t[i];
    for (int x : t){
        auto it = ms.upper_bound(x);
        
        if (it == ms.begin()){
            cout << -1 << nl;
        }
        else{
            --it;
            cout << *it << nl;
            ms.erase(it);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}