#include<bits/stdc++.h>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
int ans = 0;
int X,Y;
vector<vector<int>> g,vis;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void bfs(){
    queue<pair<int,int>> q;
    q.push({X,Y});
    while(!q.empty()){
        auto &[x,y] = q.front();
        q.pop();
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        if(g[x][y] == 2) ans++;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i],ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny]) continue;
            if(g[nx][ny] == 0) continue;
            q.push({nx,ny});
        }
    }
}

signed main(){
    cin >> n >> m;
    g.assign(n + 1, vector<int>(m + 1, 0));
    vis.assign(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        for(int j = 1; j <= m; j++){
            if(s[j] == '.') g[i][j] = 1;
            else if(s[j] == '!') g[i][j] = 2;
            else if(s[j] == '@'){
                X = i,Y = j;
                g[i][j] = 1;
            }
        }
    }
    bfs();
    cout << ans << endl;
    return 0;
}