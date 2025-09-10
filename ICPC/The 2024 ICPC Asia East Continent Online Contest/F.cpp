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

struct DSU{
    vector<int> p, sz;
    DSU(int n = 0) {ini(n);}

    void ini(int n){
        p.assign(n,-1);
        sz.assign(n,0);
    }

    int Find(int x) {
        return p[x] == x ? x : p[x] = Find(p[x]);
    }

    void mk(int x){
        p[x] = x;sz[x] = 1;
    }

    void Unite(int x,int y){
        x = Find(x); y = Find(y);
        if(x == y) return;
        if(sz[x] < sz[y]) swap(x,y);
        p[y] = x;
        sz[x] += sz[y];
    }
};


void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    vector<pii> b;
    b.reserve(n);
    for(int i = 0; i < n; i++) b.push_back({a[i],i});
    sort(b.begin(), b.end(), [](const auto &x, const auto &y){
        if(x.first != y.first) return x.first < y.first;
        return x.second < y.second;
    });

    DSU dsu(n);
    vector<int> active(n,0);
    int ans = 0;
    for(int i = 0; i < n;){
        int val = b[i].first;
        int j = i;
        vector<int> idx;
        while(j < n && b[j].first == val){
            idx.push_back(b[j].second);
            j++;
        }

        unordered_set<int> root;
        root.reserve(idx.size() * 2 + 4);
        for(int pos : idx){
            int L = pos - 1, R = pos + 1;
            if(L >= 0 && active[L]) root.insert(dsu.Find(L));
            if(R < n && active[R]) root.insert(dsu.Find(R));
        }

        for(int r : root) ans += dsu.sz[r];

        for(int pos : idx){
            active[pos] = 1;
            dsu.mk(pos);
            if(pos - 1 >= 0 && active[pos - 1]) dsu.Unite(pos,pos - 1);
            if(pos + 1 < n && active[pos + 1]) dsu.Unite(pos,pos + 1);
        }
        i = j;
    }

    cout << ans << endl;
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