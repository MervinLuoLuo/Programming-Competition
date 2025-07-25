#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

class D{
    public:
    struct edge{
        int v,rev,cap;
    };
    int n;
    vector<vector<edge>> g;
    vector<int> level, ptr;
    D(int n): n(n), g(n), level(n), ptr(n) {};
    
    void add(int u,int v,int c){
        g[u].push_back({v,(int)g[v].size(),c});
        g[v].push_back({u,(int)g[u].size() - 1,0});
    }

    bool bfs(int s,int t){
        fill(level.begin(),level.end(),-1);
        queue<int> q;
        level[s] = 0;q.push(s);
        while(!q.empty()){
            int cur = q.front();q.pop();
            for(auto &e : g[cur]){
                if(level[e.v] < 0 && e.cap > 0){
                    level[e.v] = level[cur] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] >= 0;
    }

    int dfs(int u,int t,int f){
        if(u == t || f == 0) return f;
        for(int &i = ptr[u]; i < (int)g[u].size();i++){
            auto &e = g[u][i];
            if (level[e.v] == level[u] + 1 && e.cap > 0) {
                int pushed = dfs(e.v, t, min(f, e.cap));
                if (pushed > 0) {
                    e.cap -= pushed;
                    g[e.v][e.rev].cap += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, t, LLONG_MAX)) {
                flow += pushed;
            }
        }
        return flow;
    }
};
void solve(){
    int N = 13;
    vector<int> a(N);   
    int sum = 0;
    for(int i = 0;i < 13; i++){
        cin >> a[i];sum += a[i];
    }

    D d(28);
    int src = 0,sink = 27;
    for(int i = 0; i < N; i++){
        d.add(src, 1 + i, a[i] / 3);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            d.add(1 + i,14 + j,a[j]);
        }
    }

    for(int i = 0; i < N; i++) d.add(14 + i,sink,a[i]);
    int flow = d.maxflow(src,sink);
    int ans = min(flow,sum / 4);
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}