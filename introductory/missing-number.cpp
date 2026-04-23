#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
    long long n;
    cin >> n;
    long long k = n*(n+1)/2, x;
    for (int i = 0; i<n-1; i++){
        cin >> x;
        k-=x;
    }
    cout << k;
}
 
signed main()
{
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}