/*https://www.luogu.com.cn/problem/P2014*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n,m;
vector<int> s;
VII g,dp;

int dfs(int u){
    int p = 1;
    dp[u][1] = s[u];
    for(auto v : g[u]){
        int siz = dfs(v);
        for(int i = min(p,m + 1); i ; i--){
            for(int j = 1; j <= siz && i + j <= m + 1; j++) dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[v][j]);
        }
        p += siz;
    }

    return p;
}

void solve(){
    cin >> n >> m;
    s.assign(n + 1, 0);
    g.resize(n + 1);dp.assign(n + 1, vector<int>(m + 5, 0));
    for(int i = 1; i <= n; i++){
        int k;cin >> k >> s[i];
        g[k].push_back(i);
    }
    dfs(0);
    cout << dp[0][m + 1];
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}