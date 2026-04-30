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
int l,r;
struct Edge{
    int u,v;
    int a,b;
    int w;
};
vector<Edge> e;
vector<int> fa;

int Find(int x){
    if(fa[x] == x) return fa[x];
    return fa[x] = Find(fa[x]);
}


int Kruskal(){
    int tot = 0,w = 0;
    for(int i = 1; i <= m; i++){
        int ur = Find(e[i].u),vr = Find(e[i].v);
        if(ur != vr){
            fa[ur] = vr;
            tot++;
            w += e[i].w;
        }
        if(tot == n - 1) break;
    }
    return w;
}

void ini(){
    fa.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) fa[i] = i;
}

bool cmp(Edge x,Edge y){
    return x.w < y.w;
}

void solve(){
    e.clear();e.resize(m + 1);
    for(int i = 1; i <= m; i++){
        int u,v,a,b;cin >> u >> v >> a >> b;
        e[i].u = u;
        e[i].v = v;
        e[i].a = a;
        e[i].b = b;
    }

    ini();
    for(int i = 1; i <= m; i++) e[i].w = e[i].a + e[i].b * l;
    sort(e.begin() + 1,e.end(),cmp);
    int L = Kruskal();
    ini();
    for(int i = 1; i <= m; i++) e[i].w = e[i].a + e[i].b * r;
    sort(e.begin() + 1,e.end(),cmp);
    int R = Kruskal();
    int ans = min(L,R);
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin >> n >> m >> l >> r)
    solve();
    return 0;
}