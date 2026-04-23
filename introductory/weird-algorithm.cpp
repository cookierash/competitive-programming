#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    long long n; cin >> n; cout << n << " ";
    while (n!=1){
        if (n%2==0)n/=2;
        else n=n*3+1;
        cout << n << " ";
    }
}
 
signed main()
{
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}