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

void solve(){
    int n,m;cin >> n >> m;
    vector<int> deg(n + 1, 0);
    vii g(n + 1);
    for(int i = 1; i <= m; i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v);deg[u]++;
        g[v].push_back(u);deg[v]++;
    }
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}