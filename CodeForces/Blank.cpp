#include<bits/stdc++.h>
#include <vector>
#define int long long
#define endl '\n'
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e9;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

signed main(){
    int n,m;cin >> n >> m;
    VII g(n + 1,vector<int>(m + 1, 0));
    int sx,sy,ex,ey;cin >> sx >> sy >> ex >> ey;
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        for(int j = 1;j <= m; j++){
            char c = s[j];
            if(c == '.') g[i][j] = 1;
        }
    }

    VII dis(n + 1,vector<int>(m + 1, INF));
    int cur = 0;
    queue<pair<int,int>> q;
    q.push({sx,sy});
    dis[sx][sy] = 0;
    // cerr << 1 << endl;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int nx = x + dx[k],ny = y + dy[k];
            if(nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == 0) continue;
            if(dis[nx][ny] != INF) continue;
            dis[nx][ny] = dis[x][y] + 1;
            q.push({nx,ny});
        }
    }
    // cerr << 2 << endl;
    if(dis[ex][ey] == INF) cout << -1;
    else cout << dis[ex][ey];
    return 0;
}