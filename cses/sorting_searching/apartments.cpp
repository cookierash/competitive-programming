#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
    long long n,m,k;
    cin >> n >> m >> k;
    int desired[n];
    int apartments[m];
    for (int i = 0; i < n; i++) cin >> desired[i];
    for (int i = 0; i < m; i++) cin >> apartments[i];
    sort(desired, desired + n);
    sort(apartments, apartments + m);
    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m) {
        if (abs(desired[i] - apartments[j]) <= k) {
            ans++;
            i++;
            j++;
        } else if (desired[i] < apartments[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << ans;
}
 
signed main()
{
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}