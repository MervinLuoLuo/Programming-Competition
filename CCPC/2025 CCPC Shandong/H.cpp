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
    int id;
};
vector<int> fa,res;
vector<Edge> g,e,ad;
// 找 MST
int ans = 0,ecnt = 0;
void add(int u,int v,int w){
    l++;
    g[l].u = u;
    g[l].v = v;
    g[l].w = w;
    g[l].id = l;
}

int Find(int x){
    if(fa[x] == x) return x;
    return fa[x] = Find(fa[x]);
}

void Merge(int x,int y){
    int xr = Find(x),yr = Find(y);
    if(xr != yr) fa[xr] = yr;
}

void Kruskal(){
    for(int i = 1; i <= m; i++){
        int ur = Find(g[i].u), vr = Find(g[i].v);
        if(ur != vr){
            Merge(ur,vr);
            ecnt++;
            ans += g[i].w;
            e.push_back(g[i]);// 同时记录 MST 中的边
            if(ecnt == n - 1) return;
        }
    }
}

// 初始化
void ini(){
    g.clear();g.resize(m + 1);
    res.clear();ad.clear();e.clear();
    fa.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) fa[i] = i;
    ans = 0;ecnt = 0;l = 0;
}

void solve(){
    cin >> n >> m >> k;
    ini();
    for(int i = 1; i <= m; i++){
        int u,v,w;cin >> u >> v >> w;
        if(u > v) swap(u,v);
        add(u,v,w);
    }

    // MST 必须的排序
    sort(g.begin() + 1,g.end(),[](Edge x,Edge y){
        return x.w < y.w;
    });
    Kruskal();
    // cerr << ans << endl;
    // for(int i = 0; i < e.size(); i++) cerr << e[i].id << " ";

    // 对 MST 中的边权排序
    sort(e.begin(),e.end(),[](Edge x,Edge y){
        return x.w < y.w;
    });

    // cerr << e.size() << endl;

    // 删去前 k 大且权值不为 1 的边
    int sz = e.size();
    for(int i = sz - 1; i >= max(0ll,sz - k); i--){
        auto [u,v,w,id] = e[i];
        if(w > 1){
            e.pop_back();
            ans -= w;
        }
        else res.push_back(id);
    }
    // cerr << e.size() << endl;
    // for(int i = 0; i < e.size(); i++) cerr << e[i].id << " ";

    // 将没被去除的边放入答案
    for(int i = 0; i < sz - k; i++) res.push_back(e[i].id);
    // for(auto x : res) cerr << x << " ";

    // 重新初始化 并查集
    for(int i = 1; i <= n; i++) fa[i] = i;

    // 跑一遍并查集分出连通块
    sz = e.size();
    for(int i = 0; i < sz; i++){
        auto [u,v,w,id] = e[i];
        int ur = Find(u),vr = Find(v);
        if(ur != vr){
            Merge(ur,vr);
        }
    }

    // 如果 (i,i + 1) 不在同一个连通块中就加边
    for(int i = 1; i < n; i++){
        int r = Find(i),rr = Find(i + 1);
        if(r != rr){
            Merge(i,i + 1);
            ans += 1;
            ad.push_back({i,i + 1,1,++l});
            res.push_back(l);
        }
    }
    
    cout << ad.size() << endl;
    if(ad.size() != 0){
        for(auto [u,v,w,id] : ad) cout << u << " " << v << endl;
    }
    cout << ans << endl;
    for(auto x : res) cout << x << " ";
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}