/*https://ac.nowcoder.com/acm/problem/19782*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 1e9 + 7;
int n;
VII g;
vector<int> dp;

void dfs(int u,int pre){
    for(int v: g[u]){
        if(v == pre) continue;
        dfs(v,u);
        dp[u] = ((dp[u]  + 1) * dp[v]) % MOD;
    }
}

void solve(){
    cin >> n;
    g.resize(n + 1);dp.assign(n + 1,0);
    for(int i = 1; i < n; i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) dp[i] = 1;
    dfs(1, -1);

    for(int i = 1; i <= n; i++) cout << dp[i] << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}