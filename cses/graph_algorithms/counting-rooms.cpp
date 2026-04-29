#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
#define all(v) v.begin(),v.end()
const int MAX = 1e6+5;
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
const int N = 1e4+5;
vector<int> adj[N+1];
vector<vector<bool>> vis(N+1, vector<bool>(N+1));
vector<vector<char>> grid(N+1, vector<char>(N+1));
bool flag = true;
int n,m;
 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
 
void dfs(int x, int y){
    if (vis[x][y]) return;
    vis[x][y] = true;
 
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && grid[nx][ny] != '#'){
            dfs(nx,ny);
        }
    }
}
 
void solve() {
    cin >> n >> m;
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            cin >> grid[i][j];
        }
    }
 
    int rooms = 0;
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            if (grid[i][j] == '.' && !vis[i][j]){
                dfs(i, j);
                rooms++;
            }
        }
    }
    cout << rooms;
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();