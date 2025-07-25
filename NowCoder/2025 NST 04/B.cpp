#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,m,k;
vector<vector<int>> g, vis1,vis2,trap,dist;

const int dx[] = {0, 0, 1};
const int dy[] = {1,-1,0};

void bfs(int x,int y){
    queue<pii> q;
    q.push({x,y});
    while(!q.empty()){
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        for(int i = 0; i < 3; i++){
            int nx = cx + dx[i],ny = cy + dy[i];
            if(g[nx][ny] != 1 && vis1[nx][ny] == 0 && nx >= 1 && nx <= n && ny >= 1 && ny <= m){
                vis1[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

void bfs_(int x,int y){
    queue<pii> q;
    q.push({x,y});
    while(!q.empty()){
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        for(int i = 0; i < 3; i++){
            int nx = cx + dx[i],ny = cy - dy[i];
            if(g[nx][ny] != 1 && vis2[nx][ny] == 0 && nx >= 1 && nx <= n && ny >= 1 && ny <= m){
                vis2[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

void broad(int x,int y,int cur,int val){
    if(x > cur || x < 1) return;
    if(dist[x][y] == -1 || dist[x][y] >= val) return;
    dist[x][y] = val;
    broad(x - 1, y ,cur,val);
    broad(x + 1, y ,cur,val);
}

void solve(){
    cin >> n >> m >> k;
    g.assign(n + 2,vector<int>(m + 2,1));
    vis1.assign(n + 2,vector<int>(m + 2,0));
    vis2.assign(n + 2,vector<int>(m + 2,0));
    trap.assign(n + 2,vector<int>(m + 2,0));
    dist.assign(n + 2,vector<int>(m + 2,-1));
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        s = " " + s;
        for(int j = 1; j <= m; j++) g[i][j] = s[j] - '0';
    }
    vis1[1][1] = 1;vis2[1][m] = 1;
    bfs(1,1);
    bfs_(1,m);
    for(int i = 1 ; i<= n; i++){
        for(int j = 1; j <= m; j++){
            if(vis1[i][j] && !vis2[i][j]) {trap[i][j] = 1;dist[i][j] = 0;}
        }
    }

    for(int j = m;j >= 2; j--){
        for(int i = 1; i <= n; i++){
            if(trap[i][j] && trap[i][j - 1])  dist[i][j - 1] = dist[i][j] + 1;
        }
        vector<pii> List;
        for(int i = 1; i <= n; i++){
            if(trap[i][j - 1]) List.push_back({dist[i][j - 1],i});
        }
        sort(List.begin(),List.end(),greater<pii>());
        for(auto [u,v] : List){
            broad(v - 1, j - 1,n,u);
            broad(v + 1,j - 1, n, u);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m ;j++){
            ans = max(ans,dist[i][j] + 1);
        }
    }
    if(k <= ans) yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}