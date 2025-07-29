#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,m;
vii g,dist;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

bool bfs(){
    queue<pii> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m;j++){
            if(g[i][j] == 1){
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    if(q.empty()) return 1;

    while(!q.empty()){
        auto[x,y] = q.front();q.pop();
        for(int i = 0; i< 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx > 0 && nx <= n && ny > 0 && ny <= m && dist[nx][ny] > dist[x][y] + 1){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    return 0;
}

bool check(int mid){
    int l1 = -INF, l2 = -INF, h1 = INF, h2 = INF;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dist[i][j] > mid){
                int s = i + j;
                int d = i - j;
                l1 = max(l1, s - mid);
                l2 = max(l2, d - mid);
                h1 = min(h1, s + mid);
                h2 = min(h2, d + mid);
            }
        }
    }
    if(l1 > h1 || l2 > h2) return 0;

    for(int p = 0; p < 2; p++){
        int sl = l1 + ((l1 & 1) != p ? 1 : 0);
        int sh = h1 - ((h1 & 1) != p ? 1 : 0);
        int dl = l2 + ((l2 & 1) != p ? 1 : 0);
        int dh = h2 - ((h2 & 1) != p ? 1 : 0);
        if(sl > sh || dl > dh) continue;

        int S[2] = {sl,sh};
        int D[2] = {dl,dh};
        for(int s : S){
            for(int d : D){
                int x = (s + d) >> 1;
                int y = (s - d) >> 1;
                if(x > 0 && x <= n && y > 0 && y <= m) return 1;
            }
        }
    }
    return 0;
}

void solve(){
    cin >> n >> m;
    g.assign(n + 5,vector<int>(m + 5,-1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ;j++) cin >> g[i][j];
    }
    dist.assign(n + 5,vector<int>(m + 5,INF));

    bool flag = bfs();
    if(flag){cout << (n / 2) + (m / 2) << endl;return;}

    int maxd = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) maxd = max(maxd,dist[i][j]);
    }

    int l = 0, r = maxd, ans = maxd;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){ans = mid;r = mid - 1;}
        else l = mid + 1;
    }
    
    cout << ans << endl;
}   
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}