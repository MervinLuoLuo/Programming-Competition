#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,cnt;
vector<vector<int>> g;
vector<int> vis,ans,ne;
map<pii,int> mp;
set<int> s;

void dfs(int x){
    if(vis[x]) return;
    vis[x] = 1;
    s.insert(x | 1);
    dfs(ne[x]);
    ans[x] = s.size();
}

void solve(){
    cin >> n;
    cnt = 2;
    mp.clear();
    g.assign(n + 5,vector<int>());
    ne.assign(n * 6 + 10, 0);vis.assign(n * 6+ 10, 0);ans.assign(n * 6 + 10, 0);
    for(int u = 1; u <= n; u++){
        int d;cin >> d;
        for(int i = 0; i < d; i++){
            int v;cin >> v;
            g[u].push_back(v);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < g[i].size(); j++){
            int u = i, v = g[i][j];
            if(u < v){mp[{u,v}] = cnt++;mp[{v,u}] = cnt++;}
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < g[i].size(); j++){
            int u = i, v = g[i][j];
            int val = 0;
            for(int k = 0; k < g[v].size(); k++){
                if(g[v][k] == u){val = g[v][(k + 1) % g[v].size()];break;}
            }
            ne[mp[{u,v}]] = mp[{v,val}];
        }
    }

    for(int i = 2; i < cnt; i++){
        if(vis[i] == 0){
            s.clear();
            dfs(i);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << ans[mp[{i,g[i][0]}]] << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}