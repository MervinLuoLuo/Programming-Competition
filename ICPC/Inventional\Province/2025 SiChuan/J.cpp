#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n;
string s;
VII g;
vector<int> cs,pc,f;

void dfs0(int u,int pre){
    for(int v : g[u]){
        if(s[v] == 'S' && s[u] == 'C') cs[u]++;
        if(s[v] == 'C' && s[u] == 'P') pc[u]++;
        if(v == pre) continue;
        dfs0(v,u);
    }
}

void dfs(int u,int pre){
    int sum1 = 0,sum2 = 0;
    for(int v : g[u]){
        if(s[v] == 'C') sum1 += cs[v];
        if(s[v] == 'P') sum2 += pc[v] - 1;
        if(v == pre) continue;
        dfs(v,u);
    }
    if(s[u] == 'C') f[u] = sum1 * sum2;
}

void solve(){
    cin >> n;
    cin >> s;s = " " + s;
    g.clear();
    g.resize(n + 1);
    cs.assign(n + 1, 0);pc.assign(n + 1, 0);f.assign(n + 1, 0);
    for(int i = 1; i < n; i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs0(1,0);
    dfs(1,0);
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += f[i];
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}