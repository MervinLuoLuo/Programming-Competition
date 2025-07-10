/*https://www.luogu.com.cn/problem/P1141*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n;
vector<vector<int>> g,vis;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int bfs(int x,int y){
    pii ini = {x,y};
    int ans = 0;
    queue<pii> q;
    q.push(ini);
    vis[x][y] = 1;
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        ans++;
        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i],ny = cur.second + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && !vis[nx][ny]){
                if(g[cur.first][cur.second] == 1 && g[nx][ny] == 0) {
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
                else if(g[cur.first][cur.second] == 0 && g[nx][ny] == 1) {
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    return ans;
}

void solve(){
    int m;cin >> n >> m;
    g.resize(n + 5,vector<int>(n + 5));
    for(int i  = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        for(int j = 1; j <= n; j++){
            if(s[j] == '1') g[i][j] = 1;
            else g[i][j] = 0;
        }
    }

    while(m--){
        vis.assign(n + 5,vector<int>(n + 5, 0));
        int x,y;cin >> x >> y;
        cout << bfs(x,y) << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}