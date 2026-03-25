/*https://www.luogu.com.cn/problem/P10044*/
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


void solve(){
    int n,m;cin >> n >> m;
    vector<vector<Edge>> g(n + 1),rg(n + 1);
    vector<int> ideg(n + 1, 0),odeg(n + 1, 0);
    unordered_set<int> st;
    for(int i = 1; i <= m; i++){
        int u,v,w;cin >> u >> v >> w;
        g[u].push_back({v,w});
        rg[v].push_back({u,w});
        ideg[v]++;odeg[u]++;
    }
    
    for(int i = 1; i <= n; i++){
        if(ideg[i] == 0 || odeg[i] == 0) st.insert(i);
    }

    int ans = INF;
    for(int s = 1; s <= n; s++){
        if(st.count(s) != 0) continue; 
        vector<int> dis(n + 1, INF);
        priority_queue<PII,vector<PII>,greater<PII>> q;
        dis[s] = 0;
        q.push({0,s});
        while(!q.empty()){
            auto [d,u] = q.top();
            q.pop();
            if(d != dis[u]) continue;
            for(auto [v,w] : g[u]){
                if(st.count(s) != 0) continue;
                if(d + w < dis[v]){
                    dis[v] = d + w;
                    q.push({dis[v],v});
                }
            }
        }

        for(auto [u,w] : rg[s]){
            if(dis[u] != INF) ans = min(ans,dis[u] + w);
        }
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}