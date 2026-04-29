#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define nl '\n'
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
const int N = 1e3+5;
vector<int> adj[N+1];
vector<vector<bool>> vis(N+1, vector<bool>(N+1));
vector<vector<char>> grid(N+1, vector<char>(N+1));
vector<vector<pair<int,int>>> parent(N+1, vector<pair<int,int>>(N+1, {-1,-1}));
vector<vector<int>> dist(N+1, vector<int>(N+1));
bool flag = false;
int n,m;
 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
 
void dfs(int x, int y){
    queue<pair<int,int>> q;
    vis[x][y] = true;
    if (grid[x][y] == 'B'){
        flag = true;
        return;
    }
 
    q.push({x,y});
 
    while (!q.empty()){
        auto [fx, fy] = q.front();
        q.pop();
 
    if (grid[fx][fy] == 'B'){
        flag = true;
        return;
    }
 
        for (int i = 0; i < 4; i++){
            int nx = fx + dx[i];
            int ny = fy + dy[i];
 
            if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && grid[nx][ny] != '#' && !vis[nx][ny]){
                dist[nx][ny] = dist[fx][fy] + 1;
                parent[nx][ny] = {fx, fy};
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
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
 
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            if (grid[i][j] == 'A'){
                dfs(i,j);
                break;
            }
        }
    }
 
    if (flag){
        cout << "YES" << nl;
        pair<int,int> final;
        for (int i = 1; i<=n; i++){
            for (int j = 1; j<=m; j++){
                if (grid[i][j] == 'B'){
                    final = make_pair(i,j);
                    break;
                }
            }
        }
 
        auto [i,j] = final;
        string path = "";
        while (grid[i][j] != 'A'){
            auto [ni, nj] = parent[i][j];
            if (i > ni) path.pb('D');
            else if (j > nj) path.pb('R');
            else if (i < ni) path.pb('U');
            else path.pb('L');
            i = ni; j = nj;
        }
        reverse(all(path));
        cout << path.size() << nl << path;
    }
    else cout << "NO";
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--) solve();
}