#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    VII g(n + 1);
    for(int i = 1; i<= m; i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> clr(n + 1, -1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(clr[i] == -1){
            queue<int> q;
            q.push(i);
            clr[i]  = 0;
            vector<int> cnt(2);
            bool flag = 1;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                ++cnt[clr[u]];
                for(int v : g[u]){
                    if(clr[u] == clr[v]) flag = 0;
                    else if(clr[v] == -1){
                        clr[v] = clr[u] ^ 1;
                        q.push(v);
                    }
                }
            }
            if(flag) ans += max(cnt[0],cnt[1]);
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