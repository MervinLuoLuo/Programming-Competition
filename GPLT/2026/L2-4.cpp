/*https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=2045820921833533451&page=1*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n,m;
vector<vector<PII>> g;

void bfs(int s){
    queue<int> q;
    vector<int> res,vis(n + 1, 0);
    q.push(s);res.push_back(s);
    vis[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto [w,v] : g[u]){
            if(!vis[v]){
                vis[v] = 1;
                res.push_back(v);
                q.push(v);
                break;
            }
        }
    }

    for(int i = 0; i < res.size(); i++){
        cout << res[i];
        if(i != res.size() - 1) cout << "->";
    }
}

void solve(){
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 1; i <= m; i++){
        int u,v,w;cin >> u >> v >> w;
        g[u].push_back({w,v});
    }

    for(int i = 1; i <= n ; i++){
        sort(g[i].begin(),g[i].end(),[](PII x,PII y){
            if(x.first == y.first) return x.second < y.second;
            return x.first > y.first;
        });
    }

    // for(int i = 1; i <= n ; i++){
    //     cerr << i << ": ";
    //     for(auto [w,v] : g[i]) cerr << v << "=" << w << " ";
    //     cerr << endl;
    // }
    int k;cin >> k;
    while(k--){
        int s;cin >> s;
        bfs(s);
        if(k != 0) cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}