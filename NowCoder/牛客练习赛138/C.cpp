#include <bits/stdc++.h>
#define endl '\n'
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define int long long
using namespace std;

void solve(){
    int n, k;cin >> n >> k;
    vector<vector<int>> g(n+1);
    vector<int> deg(n+1, 0);
    for(int i = 1; i < n; i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    vector<int> dist(n+1, -1);
    queue<int> q;
    dist[k] = 0;
    q.push(k);
    while(!q.empty()){
        int u = q.front(); 
        q.pop();
        for(int v : g[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int md = 0;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 1){
            md = max(md, dist[i]);
        }
    }
    cout << md + 1 << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
