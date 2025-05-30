/*https://www.luogu.com.cn/problem/P1683*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int w,h,ans = 0;
vector<vector<char>> m;
vector<vector<int>> vis;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x, int y){
    if(x < 1 or y < 1 or x > h or y > w)return;
    if(vis[x][y] or m[x][y] == '#') return;
    vis[x][y] = 1;
    ans++;
    for(int i = 0; i < 4; i++){
        dfs(x + dx[i],y + dy[i]);
    }
}

void solve(){
    cin >> w >> h;
    m.resize(h + 1,vector<char>(w + 1));
    vis.assign(h + 1,vector<int>(w + 1,0));
    int x,y;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> m[i][j];
            if(m[i][j] == '@') x = i, y = j;
        }
    }
    dfs(x,y);
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}