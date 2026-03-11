/*https://ac.nowcoder.com/acm/problem/15748*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
VII dp,g;
void dfs(int u ,int pre){
    for(int v : g[u]){
        if(v == pre) continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][1],dp[v][0]);
        dp[u][1] += dp[v][0];
    }
}

void solve(){
    int n,s;cin >>n >> s;
    dp.assign(n + 1,vector<int>(2,0));g.resize(n + 1);
    for(int i = 1; i <= n; i++) dp[i][1] = 1;
    for(int i = 1; i <= n - 1; i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(s,-1);

    cout << dp[s][1] << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}