#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define ll long long
#define nl '\n'

void solve() {
    int n,x; cin >> n;
    set<int> st;
    while (n--) {
        cin >> x;
        st.insert(x);
    }
    cout << st.size();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}