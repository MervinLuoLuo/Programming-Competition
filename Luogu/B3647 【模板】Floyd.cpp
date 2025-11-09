/*https://www.luogu.com.cn/problem/B3647*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

vii g;
vii f;
void solve(){
    int n,m;cin >> n >> m;
    g.assign(n + 1,{});
    f.assign(n + 1,vector<int>(n + 1, INF));

    for(int i = 1; i <= m; i++){
        int u,v,w;cin >> u >> v >> w;
        g[u][v] = w;
    }

    for(int k = 1;k <= n; k++){
        for(int u = 1;u <= n; u++){
            for(int v = 1; v <= n; v++){
                f[u][v] = min(f[u][v],f[u][k] + f[k][v]);
                if(u == v) f[u][v] = 0;
            }
        }
    }

    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++) cout << f[u][v] << " ";
        cout << endl;
    }
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}