#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 1e9 + 7;

void solve(){
    int n;cin >> n;
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i++) cin >> w[i];
    int m;cin >> m;
    VII g(n + 1);
    for(int i = 1; i <= m; i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v);
    }

    int ans = 0;
    vector<int> dfn(n + 1),low(n + 1),st(n + 1);
    int time = 0,tp = 0,sc = 0;// 时间戳计数 栈顶 SCC当前编号
    vector<bool> in_stack(n + 1,0);
    VII scc(n + 1);// SCC 包含的结点

    auto Tarjan = [&](auto &&self,int u) -> void {

        low[u] = dfn[u] = ++time;
        st[++tp] = u,in_stack[u] = 1;

        for(int v : g[u]){
            if(!dfn[v]){
                self(self,v);
                low[u] = min(low[u],low[v]);
            }
            else if(in_stack[v]) low[u] = min(low[u],dfn[v]);
        }

        if(dfn[u] == low[u]){
            ++sc;
            do{
                scc[sc].push_back(st[tp]);
                in_stack[st[tp]] = 0;
            }while(st[tp--] != u);
        }
    };

    for(int i = 1; i <= n; i++){
        if(!dfn[i]) Tarjan(Tarjan, i);
    }

    // cerr << sc << endl;
    // for(int i = 1; i <= sc; i++){
    //     for(int x : scc[i]) cerr << x << " ";
    //     cerr << endl;
    // }

    int res = 1;
    for(int i = 1; i <= sc; i++){
        if(scc[i].size() == 1) {ans += w[scc[i][0]];} 
        else if(scc[i].size() > 1){
            int base = INF;
            for(int x : scc[i]) base = min(base,w[x]);
            int cnt = 0;
            for(int x : scc[i]){
                if(w[x] == base) cnt++;
            }
            // cerr << base << " " << cnt << endl;
            ans += base;
            res = res * cnt % MOD;
        }
    }

    cout << ans << " " << res << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}