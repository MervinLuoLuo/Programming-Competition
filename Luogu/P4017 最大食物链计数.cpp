/*https://www.luogu.com.cn/problem/P4017*/
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
const int MOD = 80112002;

void solve(){
    int n,m;cin >> n >> m;
    vii g(n + 1);
    vector<int> ideg(n + 1, 0), odeg(n + 1,0);
    for(int i = 1; i <= m; i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v);
        ideg[v]++;odeg[u]++;
    }
    
    vector<int> dp(n + 1, 0);
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(ideg[i] == 0) {
            dp[i] = 1;
            q.push(i);
        }
    }

    int ans = 0;
    while(!q.empty()){
        int cur =q.front();
        q.pop();
        for(int i = 0; i < g[cur].size(); i++){
            int nw = g[cur][i];
            dp[nw] = (dp[nw] + dp[cur]) % MOD;
            ideg[nw]--;
            if(ideg[nw] == 0){
                if(odeg[nw] == 0) ans = (ans + dp[nw]) % MOD;
                else q.push(nw);
            }
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}