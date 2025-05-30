/*https://codeforces.com/problemset/problem/2060/E*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
vector<int> df,dg;
vector<vector<int>> cg;
int find(vector<int> &dsu,int x){
    if(dsu[x] != x) dsu[x] = find(dsu,dsu[x]);
    return dsu[x];
}

void unite(vector<int> &dsu,int x,int y){
    int fx = find(dsu,x),fy = find(dsu,y);
    if(fx != fy) dsu[fx] = fy;
}

void solve(){
    int n,m1,m2;cin >>n >> m1 >> m2;
    df.resize(n + 5);dg.resize(n + 5);cg.resize(n + 5);
    for(int i = 1; i <= n; i++){
        df[i] = i;dg[i] = i;cg[i].clear();
    }
    vector<pii> tmp(m1);//因为要先确定图 G 而题目先输入 F 再输入 G 我们先把 F 存起来
    for(int i = 0; i < m1; i++){
        int u,v;cin >> u >> v;
        tmp[i] = {u,v};
    }
    for(int i = 0; i < m2; i++){
        int u,v;cin >> u >> v;
        unite(dg,u,v);
    }
    int d = 0;
    for(int i = 0; i < m1; i++){
        int u = tmp[i].first, v = tmp[i].second;
        if(find(dg,u) != find(dg,v)) d++;//跨越 G 中的连通块删除 d++
        else unite(df,u,v);
    }

    //分组(相当于dfs的染色)
    for(int i = 1; i <= n; i++){
        int root = find(dg,i);
        cg[root].push_back(i);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(cg[i].empty()) continue;
        unordered_set<int> fr;//F的根的集合(去重所以用u_set)
        for(int j : cg[i]){
            fr.insert(find(df,j));
        }
        ans += fr.size() - 1;
    }
    cout << ans + d << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}