#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n;
vector<vector<int>> g;
vector<pii> ans;
vector<int> vis;

void dfs(int cur, bool stat){
    vis[cur] = 1;

    for(int to : g[cur]){
        if(vis[to]) continue;
        if(stat) ans.push_back({to,cur});
        else ans.push_back({cur,to});
        dfs(to, !stat);
    }
}


void solve(){
    cin >> n;
    g.assign(n + 5,vector<int>());
    ans.clear();vis.assign(n + 5, 0);
    for(int i = 0 ; i < n -1 ; i++){
        int u,v;cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int be = 0;
    while(be < n && g[be].size() != 2) be++;
    if(be >= n){no;return;}

    ans.push_back({be,g[be][0]});
    ans.push_back({g[be][1],be});
    vis[be] = 1;

    dfs(g[be][0],1);
    dfs(g[be][1],0);
    
    yes;
    sort(ans.begin(),ans.end());
    for(auto [u,v] : ans) cout << u  + 1 << ' ' << v + 1 << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}