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
struct dsu{
    vector<int> fa;
    dsu(){}
    dsu(int n){
        ini(n);
    }
    void ini(int n){
        fa.resize(n + 1);
        for(int i = 1; i <= n; i++) fa[i] = i;
    }

    int Find(int x){
        if(fa[x] == x) return x;
        return fa[x] = Find(fa[x]);
    }

    void Merge(int u,int v){
        int ur = Find(u),vr = Find(v);
        if(ur != vr) fa[ur] = vr;
    }
};

void solve(){
    cin >> n >> m;
    dsu d1(n),d2(n);
    int ans = 0;
    for(int i = 1; i <= m; i++){
        int u,v,col;cin >> u >> v >> col;
        if(col == 1){
            int ur = d1.Find(u),vr = d1.Find(v);
            if(ur != vr){
                d1.Merge(u,v);
                ans++;
            }
        }
        else ans++;
        int ur = d2.Find(u),vr = d2.Find(v);
        if(ur != vr){
            d2.Merge(u,v);
            ans--;
        }
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}