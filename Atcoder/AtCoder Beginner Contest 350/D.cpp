#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n,m;
vector<int> fa,p,cnt;
vector<PII> e;

int Find(int x){
    if(fa[x] == x) return x;
    return fa[x] = Find(fa[x]);
}

void Union(int x,int y){
    int rx = Find(x),ry = Find(y);
    if(rx == ry) return;
    if(p[rx] < p[ry]) swap(rx,ry);
    fa[ry] = rx;
    p[rx] += p[ry];
}

void solve(){
    cin >> n >> m;
    if(m ==0){cout << 0 << endl;return;}
    fa.assign(n + 1, 0);p.assign(n + 1, 1);
    iota(fa.begin() + 1,fa.end(),1LL);
    cnt.assign(n + 1, 0);

    for(int i = 1; i <= m; i++){
        int u,v;cin >> u >> v;
        Union(u,v);
        e.push_back({u,v});
    }

    for(auto [u,v] : e){
        int root = Find(u);
        cnt[root]++;
    }

    int ans = 0; 
    for(int i = 1 ; i<= n; i++){
        if(Find(i) == i){
            int tol = p[i] * (p[i] - 1) / 2;
            ans += tol - cnt[i];
        }
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}