#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

struct P{
    int x,y;
    int to;
};
struct Pre{
    int x,y;
    int to;
    bool st;
};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
char d[] = {'D','U','L','R'};
int n,m;
VII g;
vector<vector<vector<int>>> vis;
vector<vector<vector<Pre>>> pre;
int sx = 0,sy = 0,ex = 0,ey = 0;
string ans;

void bfs(){
    queue<P> q;
    for(int k = 0; k < 4; k++){
        int nx = sx + dx[k],ny = sy + dy[k];
        if(nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == 0) continue;
        if(!vis[nx][ny][k]){
            vis[nx][ny][k] = 1;
            pre[nx][ny][k] = {sx,sy,-1,1};
            q.push({nx,ny,k});
        }
    }
    int edx = 0,edy = 0,edt = -1;
    while(!q.empty()){
        auto[x,y,to] = q.front();
        q.pop();
        if(x == ex && y == ey) {
            edx = x,edy = y,edt = to;
            while(1){
                ans += d[edt];
                auto p = pre[edx][edy][edt];
                if(p.st) break;
                edx = p.x;edy = p.y;edt = p.to;
            }
            reverse(ans.begin(),ans.end());
            return;
        }

        for(int k = 0; k < 4; k++){
            if(g[x][y] == 2 && k != to) continue;
            if(g[x][y] == 3 && k == to) continue;

            int nx = x + dx[k],ny = y + dy[k];
            if(nx < 1 || ny < 1 || nx > n || ny > m || g[nx][ny] == 0) continue;
            if(vis[nx][ny][k]) continue;

            vis[nx][ny][k] = 1;
            pre[nx][ny][k] = {x,y,to,0};
            q.push({nx,ny,k});
        }
    }
}

void solve(){
    cin >> n >> m;
    g.assign(n + 1,vector<int>(m + 1, 0));
    vis.assign(n + 1,VII(m + 1,vector<int>(4,0)));
    pre.assign(n + 1, vector<vector<Pre>>(m + 1, vector<Pre>(4)));
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        for(int j = 1; j <= m; j++){
            if(s[j] == '#') g[i][j] = 0;
            else if(s[j] == '.') g[i][j] = 1;
            else if(s[j] == 'o') g[i][j] = 2;
            else if(s[j] == 'x') g[i][j] = 3;
            else if(s[j] == 'S') g[i][j] = 1,sx = i,sy = j;
            else g[i][j] = 1,ex = i,ey = j;
        }
    }

    bfs();
    if(!ans.empty() || (sx == ex && sy == ey)){
        cout << "Yes" << endl;
        cout << ans << endl;
    }
    else cout << "No";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}