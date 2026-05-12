#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n,m,k;
struct Edge{
    int v;
    int type;
    int len;
};
struct Pre{
    int cur;
    int type;
    int len;
    bool Next = 0;
};

vector<vector<Edge>> g,vg;
vector<bool> vis;
vector<set<int>> pre;
VII tic;

void bfs(int s){
    queue<Pre> q;
    q.push({1,0,0,0});
    while(!q.empty()){
        auto &[u,t,len,Next] = q.front();
        q.pop();
        vis[u] = 1;
        
    }
}

void solve(){
    cin >> n >> m >> k;
    g.clear();g.resize(n + 1);
    vg.clear();vg.resize(n + 1);
    tic.clear();tic.resize(m + 1);
    vis.assign(n + 1, 0);
    pre.clear();pre.resize(n + 1);
    for(int i = 1; i <= m; i++){
        int u,v,type,len;cin >> u >> v >> type >> len;
        g[u].push_back({v,type,len});
        g[v].push_back({u,type,len});
    }

    for(int i = 1; i <= k; i++){
        int type,len;cin >> type >> len;
        tic[type].push_back(len);
    }

    for(int i = 1; i <= m; i++){
        sort(tic[i].begin(),tic[i].end());
    }

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}