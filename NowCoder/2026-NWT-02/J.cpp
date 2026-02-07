#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n,m;
VII  g;
vector<int> deg,dis,ans;
map<int,deque<int>> mp;

void bfs(){
    for(auto &[x,q] : mp | views::reverse ){
        // cerr << x << ": ";
        for(int &it : q){
            if(dis[it] == INF) dis[it] = -1;
            ans[it] = dis[it];
            dis[it] = 0;
            // cerr << it << " ";
        }
        // cerr << endl;
        while(!q.empty()){
            int u = q.front();
            q.pop_front();
            for(int &v : g[u]){
                if(deg[v] >= x) continue;
                if(dis[v] > dis[u] + 1){
                    dis[v] = dis[u] + 1;
                    q.push_back(v);
                }
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    g.assign(n + 1,{});
    deg.assign(n + 1, 0);dis.assign(n + 1, INF);ans.assign(n + 1, 0);
    for(int i = 1; i <= m; i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v);g[v].push_back(u);
        deg[u]++;deg[v]++;
    }

    for(int i = 1; i <= n; i++){
        mp[deg[i]].push_back(i);
    }
    bfs();

    for(int i = 1; i <= n; i++) cout << ans [i] << " ";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}