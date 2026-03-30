/* https://www.luogu.com.cn/problem/P10044 */
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
struct Edge{
    int v;
    int w;
};
int n,m,ans = INF;
vector<vector<Edge>> e;
vector<unordered_map<int,int>> g, rg;
vector<int> node;

void add(int u,int v,int w){
    if(g[u].count(v)){
        g[u][v] = min(g[u][v],w);
        rg[v][u] = g[u][v];
        return;
    }
    g[u][v] = w;
    rg[v][u] = w;
}

void build(){
    for(int i = 1; i <= n; i++){
        if(g[i].size() == 0) continue;
        node.push_back(i);

        for(auto [v,w] : g[i]){
            node.push_back(v);
            e[i].push_back({v,w});
        }
    }

    sort(node.begin(),node.end());
    node.erase(unique(node.begin(),node.end()),node.end());
}

void solve(){
    cin >> n >> m;
    e.resize(n + 1);g.resize(n + 1);rg.resize(n + 1);
    for(int i = 1; i <= m; i++){
        int u,v,w;cin >> u >> v >> w;
        if(u == v) ans = min(ans,w);
        else add(u,v,w);
    }

    // 压缩图
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(g[i].size() == 0 || rg[i].size() == 0 || (g[i].size() == 1 && rg[i].size() == 1)) q.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(g[u].size() == 0 || rg[u].size() == 0) continue;
        auto &[x,w1] = *rg[u].begin();
        auto &[y,w2] = *g[u].begin();
        // 合并单入单出点
        add(x,y,w1 + w2);

        // 更新后再处理
        vector<int> out,in;
        for(auto [v,w] : g[u]) out.push_back(v);
        for(auto [v,w] : rg[u]) in.push_back(v);

        for(int x : out){
            rg[x].erase(u);
            g[x].erase(u);
            if(g[x].size() == 0 || rg[x].size() == 0 || (g[x].size() == 1 && rg[x].size() == 1)) q.push(x);
        }

        for(int x: in){
            rg[x].erase(u);
            g[x].erase(u);
            if(g[x].size() == 0 || rg[x].size() == 0 || (g[x].size() == 1 && rg[x].size() == 1)) q.push(x);
        }
        // for(auto [v,w] : g[u]){
        //     rg[v].erase(u);
        //     g[v].erase(u);
        //     if(g[v].size() == 0 || rg[v].size() == 0 || (g[v].size() == 1 && rg[v].size() == 1)) q.push(v);
        // }

        // for(auto [v,w] : rg[u]){
        //     rg[v].erase(u);
        //     g[v].erase(u);
        //     if(g[v].size() == 0 || rg[v].size() == 0 || (g[v].size() == 1 && rg[v].size() == 1)) q.push(v);
        // }

        g[u].clear();
        rg[u].clear();
    }

    // 重新建图
    build();

    for(int i : node){
        // 每个节点跑 Dij
        priority_queue<PII,vector<PII>,greater<PII>> pq;
        vector<int> dis(n + 1,INF), vis(n + 1, 0);
        for(auto [v,w] : e[i]){
            dis[v] = w;
            pq.push({w,v});
        }

        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(auto [v,w] : e[u]){
                if(dis[v] > d + w){
                    dis[v] = d + w;
                    pq.push({dis[v],v});
                }
            }
        }

        ans = min(ans,dis[i]);
    }

    if(ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}