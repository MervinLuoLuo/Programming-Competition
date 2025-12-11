/*https://www.luogu.com.cn/problem/P3574*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n;
vector<int> w,f,g;
VII adj;

void dfs(int fa,int u){
    //存子树
    vector<int> wait;
    for(int v : adj[u]){
        if(v == fa)  continue;
        dfs(u,v);
        wait.push_back(v);
    }

    //按跑完了没装完的时间贪心排序
    sort(wait.begin(),wait.end(), [](int a,int b){
        return f[a] - g[a] > f[b] - g[b];
    });

    //更新子树节点
    for(int v : wait){
        //更新装机时间
        f[u] = max(f[u],g[u] + 1 + f[v]);
        //更新跑这个点一圈所需时间
        g[u] += g[v] + 2; 
    }

    //如果装的时间比跑的时间还长
    if(w[u] > g[u] && u != 1) f[u] = max(f[u],w[u]);
}

void solve(){
    cin >> n;
    w.assign(n + 1,0),f.assign(n + 1,0),g.assign(n + 1,0);
    adj.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n - 1; i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    

    dfs(0,1);
    cout << max(f[1],g[1] + w[1]) << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}