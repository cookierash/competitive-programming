#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
const int MAX = 1e6+5;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve() {
    int n,res=0; cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    
    for (int i = 0; i < n; i++){
        int sum = 0;
        for (int j = i; j<n; j++){
            sum += d[j];
            int len = j-i+1;
            if (sum%len != 0) continue;
            int avg = sum/len;

            for (int k = i; k<=j; k++){
                if (d[k] == avg){
                    res++;
                    break;
                }
            }
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