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
int ans = maxn;
vector<vector<int>> g;
vector<int> cnt;

void dfs(int x,int y,int cur){
    if(x == n + 1){
        for(int i = 1; i <= n; i++){
            if(cnt[i] != 2) return;
        }
        ans = min(ans,cur);
        return;
    }
    if(y == n + 1) {dfs(x + 1, x + 2, cur);return;}

    cnt[x]++,cnt[y]++;
    if(cnt[x] <= 2 && cnt[y] <= 2){
        dfs(x,y + 1, cur + (g[x][y] == 0));
    }
    cnt[x]--,cnt[y]--;
    dfs(x, y + 1, cur + g[x][y]);
}

void solve(){
    cin >> n >> m;
    g.resize(n + 5,vector<int>(n + 5));
    cnt.resize(n + 5);
    for(int i = 0; i < m; i++){
        int u,v;cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    dfs(1,2,0);
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}