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

struct Edge{
    int u,v;
    int x;
    int y;
};

void solve(){
    int n;cin >> n;
    vector<int> deg(n,0);
    vii g(n),gg(n);
    vector<Edge> e(n - 1);
    for(int i = 0; i < n - 1; i++){
        int u,v,x,y;cin >> u >> v >> x >> y;
        u--,v--;
        if(x > y){
            g[u].push_back(v),gg[v].push_back(u);
            deg[u]++;
        }
        else{
            g[v].push_back(u),gg[u].push_back(v);
            deg[v]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(deg[i] == 0) q.push(i);
    }

    vector<int> p(n);
    for(int i = 1; i <= n; i++){
        int u = q.front();
        p[u] = i;
        q.pop();
        for(const auto &v : gg[u]){
            deg[v]--;
             if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    for(auto [u,v,x,y] : e){
        if(x > y) assert(p[u] > p[v]);
        else if(x < y) assert(p[v] > p[u]);
    }

    for(int x : p) cout << x << " ";
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}