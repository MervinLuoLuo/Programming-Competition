#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

int x,y,p,Q;
int f[105][105][2];
int vis[105][105][2];
struct Stat{
    int s,w,side;
};

queue<Stat> q;
void bfs(){
    f[x][y][0] = 0;
    vis[x][y][0] = 1;
    q.push({x,y,0});
    while(!q.empty()){
        int ns = q.front().s,nw = q.front().w, nside = q.front().side;
        
        for(int i = 0; i <= p; i++){//Sheep
            for(int j = 0; j <= p - i; j++){
            int nws = ns - i, nww = nw - j;
            int cnt = f[ns][nw][nside];
            if((nws > 0 && nws + Q < nww) || nws < 0 || nww < 0 || vis[nws][nww][nside] == 1 ) continue;
            vis[nws][nww][nside] = 1;
            cnt++;

            f[x - nws][y - nww][1 - nside] = cnt;
            q.push({x-nws,y-nww,1-nside});
            }
        }

        q.pop();
    }
}

void solve(){
    cin >> x >> y >> p >> Q;

    memset(f,0x3f3f3f3f3f3f,sizeof(f));
    memset(vis,0,sizeof(vis));
    if(p >= x) {cout << 1 << endl;return;}
    if(x + p + Q < y){cout << -1 << endl;return;}
    bfs();
    int ans = maxn;
    for(int i = 0; i <= y; i++){
        ans = min(ans,f[x][i][1]);
    }

    if(ans == maxn) cout << -1 << endl;
    else cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}