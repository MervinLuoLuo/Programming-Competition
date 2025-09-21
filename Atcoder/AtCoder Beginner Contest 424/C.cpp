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
int n;
vii g;
vector<int> vis;

void dfs(int x){
    vis[x] = 1;
    for(int v : g[x]){
        if(!vis[v]) dfs(v);
    }
}

void solve(){
    int n;cin >> n;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int u,v;cin >> u >> v;
        g[u].push_back(i);
        g[v].push_back(i);
    }

    vis[0] = 1;
    dfs(0);

    int ans = 0;
    for(int i = 1;i <= n; i++){
        if(vis[i]) ans++;
    }

    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}