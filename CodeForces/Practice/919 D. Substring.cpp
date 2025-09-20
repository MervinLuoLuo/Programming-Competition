/*https://codeforces.com/problemset/problem/919/D*/
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

void solve(){
    int n,m;cin >> n >> m;
    vector<int> val(n + 1),ideg(n + 1, 0);
    vii dp(n + 1, vector<int>(27,0));
    vii g(n + 1);
    string s;cin >> s; s = " " + s;
    for(int i = 1; i <= n; i++){
        val[i] = s[i] - 'a' + 1;
        dp[i][val[i]]++;
    }

    for(int i = 1; i <= m; i++){
        int u,v;cin >> u >> v;
        g[u].push_back(v);
        ideg[v]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(ideg[i] == 0) q.push(i);
    }

    int sum = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ideg[cur] = -1;
        sum++;
        for(int i = 0; i < g[cur].size();i++){
            int nw = g[cur][i];
            for(int j = 1; j <= 26; j++){
                if(val[nw] == j) dp[nw][j] = max(dp[nw][j], dp[cur][j] + 1);
                else dp[nw][j] = max(dp[nw][j],dp[cur][j]);
            }
            ideg[nw]--;
            if(ideg[nw] == 0) q.push(nw);
        }
    }
    if(sum < n) cout << -1 << endl;
    else{
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 26; j++){
                ans = max(ans,dp[i][j]);
            }
        }
        cout << ans << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}