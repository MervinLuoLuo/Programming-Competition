/*https://www.luogu.com.cn/problem/P1195*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n,m,k,l;
struct Edge{
    int u,v,w;
};
vector<int> par;
vector<Edge> g;

void add(int u,int v,int w){
    l++;
    g[l].u = u;
    g[l].v = v;
    g[l].w = w;
}

int Find(int x){
    if(par[x] == x) return x;
    return par[x] = Find(par[x]);
}

void Merge(int x,int y){
    int rx = Find(x),ry = Find(y);
    par[x] = y;
}

void Kruskal(){
    int tot = 0;// 选中的边
    int ans = 0;// 选中的边权和
    for(int i = 1; i <= m; i++){
        int xr = Find(g[i].u),yr = Find(g[i].v);
        if(xr != yr){
            Merge(xr,yr);
            tot++;
            ans += g[i].w;
            if(tot == n - k){
                cout << ans << endl;
                return;
            }
        }
    }
    cout << "No Answer" << endl;
}


void solve(){
    cin >> n >> m >> k;
    if(n == k){
        cout << 0 << endl;
        return;
    }
    g.resize(m + 1);
    par.assign(n + 1,0);
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 1;  i<= m; i++){
        int u,v,w;cin >> u >> v >> w;
        add(u,v,w);
    }
    sort(g.begin() + 1,g.end(),[](Edge x,Edge y){
        return x.w < y.w;
    });

    Kruskal();
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}