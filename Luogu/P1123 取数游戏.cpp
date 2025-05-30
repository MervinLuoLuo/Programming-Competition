/*https://www.luogu.com.cn/problem/P1123*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,m;
vector<vector<int>> g;
int dx[9] = {0,1,-1,0,0,1,-1,1,-1};
int dy[9] = {0,0,0,1,-1,-1,1,1,-1}; 
int ans,sum;
int vis[8][8];

void dfs(int x, int y){
    if(y > m){
        dfs(x + 1,1); 
        return;
    }
    if(x > n){
        ans = max(ans,sum);
        return;
    }

    dfs(x,y+1);

    if(!vis[x][y]){
        sum += g[x][y];
        for(int i = 0; i <= 8; i++){
            int curx = x + dx[i],cury = y + dy[i];
            if(curx >0 && cury > 0 && curx <= n && cury <= m) vis[curx][cury] += 1;
            //计数式标记法
        }
        dfs(x,y + 1);
        for(int i = 0; i <= 8; i++){
            int curx = x + dx[i],cury = y + dy[i];
            if(curx > 0 && cury > 0 && curx <= n && cury <= m) vis[curx][cury] -= 1;
        }
        sum -= g[x][y];
    }
}

void solve(){
    cin >> n >> m;
    g.assign(n + 1,vector<int>(m + 1,0));
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> g[i][j];
    }
    ans = 0;sum = 0;
    dfs(1,1);
    cout << ans << endl;
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