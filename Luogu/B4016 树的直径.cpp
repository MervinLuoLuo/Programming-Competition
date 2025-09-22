/*https://www.luogu.com.cn/problem/B4016*/
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
int n, ans;
vii G;
vector<int> dp;

void dfs(int u,int p){
    for(int v : G[u]){
        if(v == p) continue;
        dfs(v,u);
        ans = max(ans,dp[u] + dp[v] + 1);
        dp[u] = max(dp[u],dp[v] + 1);
    }
}

void solve(){
    cin >> n;
    G.resize(n + 1);
    dp.assign(n + 1, 0);
    for(int i = 0; i < n- 1; i++){
        int u,v;cin >> u >>v;
        G[u].push_back(v);G[v].push_back(u);
    }

    dfs(1,0);
    cout << ans << endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}