/*https://www.luogu.com.cn/problem/CF20C*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n,m;
vector<vector<PII>> g;
vector<int> dis,vis,pre;

void dij(){
    priority_queue<PII,vector<PII>,greater<PII>> pq;
    dis[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;

        for(auto &[v,w] : g[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pre[v] = u;
                pq.push({dis[v],v});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 1; i <= m; i++){
        int u,v,w;cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dis.assign(n + 1, INF);vis.assign(n + 1, 0);pre.assign(n + 1, 0);
    
    dij();
    if(dis[n] == INF){
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    for(int x = n; x; x = pre[x]) ans.push_back(x);
    reverse(ans.begin(),ans.end());
    for(auto x : ans) cout << x << " ";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}