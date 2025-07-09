/*https://www.luogu.com.cn/problem/P1746*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n;int bx,by,ex,ey;
vector<vector<int>> g,dist;
queue<pii> q;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

void bfs(int x,int y){
    q.push({x,y});
    dist[x][y] = 0;
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int curxx = curx + dx[i], curyy = cury + dy[i];
            if(curxx <= 0 || curyy <= 0 || curxx > n || curyy > n) continue;
            if(g[curxx][curyy] == 1) continue;
            if(dist[curxx][curyy] >= 0) continue;
            q.push({curxx,curyy});
            dist[curxx][curyy] = dist[curx][cury] + 1;
        }
    }
}

void solve(){
    cin >> n;
    g.resize(n + 5, vector<int> (n + 5, -1));
    dist.resize(n + 5,vector<int>(n + 5, -1));
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        for(int j = 1; j <= n; j++) g[i][j] = s[j - 1] - '0';
    }
    cin >> bx >> by >> ex >> ey;
    bfs(bx,by);
    cout << dist[ex][ey] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}