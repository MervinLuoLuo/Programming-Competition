/*https://www.luogu.com.cn/problem/P1352*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n;
vector<int> w,stat,vis;
VII g,dp;

void calc(int u){
    vis[u] = 1;
    for(int v : g[u]){
        if(vis[v]) continue;
        calc(v);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][0] ,dp[v][1]);
    }
}

void solve(){
    cin >> n;
    w.assign(n + 1, 0);stat.assign(n + 1, 0);vis.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> w[i];
    g.resize(n + 1);
    dp.assign(n + 1,vector<int>(2,0));
    
    for(int i = 1; i <= n - 1; i++){
        int u,v;cin >> v >> u;
        g[u].push_back(v);
        stat[v] = 1;
    }

    int root = 0;
    for(int i = 1; i <= n; i++){
        if(stat[i] == 0) root = i;
        dp[i][1] = w[i];
    }

    calc(root);
    cout << max(dp[root][1],dp[root][0]) << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}