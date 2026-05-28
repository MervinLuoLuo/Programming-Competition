/*https://acm.hdu.edu.cn/contest/problem?cid=1203&pid=1002*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    map<int,int> hmp,vmp;
    VII g(n + 1,vector<int>(n + 1,0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cin >> g[i][j];
    }

    for(int i = 1; i <= n; i++){
        vector<bool> vis(n * n + 2, 0);
        for(int j = 1; j <= n; j++){
            if(!vis[g[i][j]]){
                hmp[g[i][j]]++;
                vis[g[i][j]] = 1;
            }
        }
    }

    for(int j = 1; j <= n; j++){
        vector<bool> vis(n * n + 2, 0);
        for(int i = 1; i <= n; i++){
            if(!vis[g[i][j]]){
                vmp[g[i][j]]++;
                vis[g[i][j]] = 1;
            }
        }
    }

    vector<int> ans;
    vector<bool> flag(n * n + 2,0);
    for(auto &[it,cnt] : hmp){
        if(cnt == n) flag[it] = 1;
    }

    for(auto &[it,cnt] : vmp){
        if(cnt == n && flag[it]) ans.push_back(it);
    }

    cout << ans.size() << endl;
    if(!ans.empty()){
        for(int x : ans) cout << x << " ";
    }

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