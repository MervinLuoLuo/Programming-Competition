/*https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=2045820921833533450&page=1*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n;
VII g;
vector<int> a,deg,f;
set<int> leaf;

void dfs(int u,int pre){
    for(int v : g[u]){
        if(v == pre) continue;
        f[v] = min(f[u],a[v]);
        dfs(v,u);
    }
}

void solve(){
    cin >> n;
    g.resize(n + 1);
    a.assign(n + 1, 0);f.assign(n + 1, INF);deg.assign(n + 1 ,0);
    for(int v = 1; v < n; v++){
        int u;cin >> u >> a[v];
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++,deg[v]++;
    }

    for(int i = 1; i < n; i++){
        if(deg[i] == 1) leaf.insert(i);
    }

    dfs(0,-1);
    // for(int i = 1; i < n; i++) cerr << f[i] << " ";
    int ans = 0;
    vector<int> res;
    for(int i = 1; i < n; i++){
        if(leaf.count(i)){
            if(ans < f[i]){
                ans = f[i];
                res.clear();
                res.push_back(i);
            }
            else if(ans == f[i]) res.push_back(i);
        }
    }
    
    cout << ans << endl;
    for(int i = 0; i < res.size() ; i++){
        cout << res[i];
        if(i != res.size() - 1) cout << " ";
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}