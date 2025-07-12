#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
#define pii pair<int,int>
using namespace std;
const int maxn = 1e9;
// const int INF = 1e19;
int n,m;
vector<int> dsu;
vector<int> h;

int Find(int x){
    if(x == dsu[x]) return x;
    else return dsu[x] = Find(dsu[x]);
}
void Union(int u,int v){
    int fu = Find(u),fv = Find(v);
    if(fu != fv){dsu[v] = fu;h[fu]++;}
}
void solve(){
    cin >> n >> m;
    dsu.assign(n + 5,0);
    h.assign(n + 5, 1);
    for(int i = 1; i <= n; i++) dsu[i] = i;
    for(int i = 0; i < m; i++){
        int u,v;cin >> u >> v;
        Union(u,v);
    }
    sort(h.begin() + 1,h.begin() + n + 1,greater<int>());
    cout << h[1] << " ";
    for(int i = 1; i <= n; i++){
        if(h[i] != h[1]) {cout << h[i];break;}
    }
    cout << endl;
}

signed main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}