/*https://www.luogu.com.cn/problem/P1111*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
vector<int> dsu;
struct Node{
    int u,v,t;
};

int find(int x){
    if(dsu[x] != x) dsu[x] = find(dsu[x]);
    return dsu[x];
}

bool cmp(const Node a,const Node b){
    return a.t < b.t;
}

void solve(){
    int n,m;cin >> n >> m;
    dsu.resize(n + 5);
    for(int i = 1; i <= n; i++) dsu[i] = i;
    vector<Node> node(m + 5);
    for(int i = 1; i <= m; i++){
        int u,v,t;cin >> u >> v >> t;
        node[i].u = u;node[i].v = v;node[i].t = t;
    }
    int ans = 0,cnt = n;
    sort(node.begin() + 1,node.begin() + m + 1,cmp);
    for(int i = 1; i <= m; i++){
        Node cur = node[i];
        int fu = find(cur.u), fv = find(cur.v);
        if(fu != fv){dsu[fu] = fv;ans = cur.t;cnt--;}
    }
    if(cnt != 1) cout << -1 << endl;
    else cout << ans <<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}