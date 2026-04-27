#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
const int MAX = 1e6+5;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int res = 0;
bool board[8][8];
bool reserved[8][8];

bool safe(int r, int c){
    for (int i = 0; i < r; i++){
        if (board[i][c]) return false;
    }

    for (int i = r-1, j = c-1; i>=0 && j>=0; i--, j--){
        if (board[i][j]) return false;
    }

    for (int i = r-1, j = c+1; i>=0 && j<8; i--, j++){
        if (board[i][j]) return false;
    }

    return true;
}

void backtrack(int r){
    if (r == 8){
        res++;
        return;
    }

    for (int c = 0; c < 8; c++){
        if (safe(r, c) && !reserved[r][c]){
            board[r][c] = 1;
            backtrack(r+1);
            board[r][c] = 0;
        }
    }
}

void solve() {
    char c;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> c;
            if (c == '*') reserved[i][j] = 1;
            else reserved[i][j] = 0;
        }
    }
    backtrack(0);
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