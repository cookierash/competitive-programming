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
    int n;
    long long s;
    cin >> n >> s;
 
    vector<pair<long long,int>> v(n);
 
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
 
    sort(v.begin(), v.end());
 
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        long long target = s - v[i].first;
 
        while (l < r) {
            long long sum = v[l].first + v[r].first;
 
            if (sum == target) {
                cout << v[i].second << " " << v[l].second << " " << v[r].second;
                return;
            }
            else if (sum < target) l++;
            else r--;
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