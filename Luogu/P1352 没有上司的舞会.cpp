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
vector<int> val,vis,isp;
VII g,f;

void dfs(int u){
    vis[u] = 1;
    for(auto v : g[u]){
        if(vis[v]) continue;
        //返回上层
        dfs(v);
        // 参加
        f[u][1] += f[v][0];
        // 不参加
        f[u][0] += max(f[v][0],f[v][1]);
    }
}

void solve(){
    cin >> n;
    val.assign(n + 1, 0);vis.assign(n + 1, 0);isp.assign(n + 1, 0);
    g.resize(n + 1);f.assign(n + 1,vector<int>(2,0));
    for(int i = 1; i <= n; i++) cin >> val[i];
    for(int i = 1; i <= n - 1; i++){
        int u,v;cin >> v >> u;
        g[u].push_back(v);
        isp[v] = 1;
    }
    for(int i = 1; i <= n; i++) f[i][1] = val[i];

    for(int i = 1; i <= n; i++){
        if(!isp[i]){ 
            dfs(i);
            cout << max(f[i][0],f[i][1]);
            return;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}