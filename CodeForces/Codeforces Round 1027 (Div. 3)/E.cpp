#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
vector<int> a,r;
vector<vector<int>> g;

void dfs(int u,int p,int pc,int nc){
    r[u] = a[u] + nc;
    int npc = max(0LL,a[u] + nc);
    int nnc = max(0LL,pc - a[u]);
    for(int v : g[u]){
        if(v == p) continue;//防止他往回走
        dfs(v,u,npc,nnc);
    }
}

void solve(){
    int n;cin >> n;
    a.assign(n,0);
    for(int &x : a)cin >> x;
    r.assign(n,0);
    g.assign(n,vector<int>());
    for(int i =0; i < n -1;i++){
        int u,v;cin >> u >> v;
        --u,--v;
        g[u].push_back(v);g[v].push_back(u);
    } 
    dfs(0,-1,0,0);
    for(auto it : r) cout << it << " ";
    cout << endl;
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