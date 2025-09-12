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
    vii g(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> g[i][j];
    }

    vii dp(n + 1,vector<int>(m + 1, 0));
    dp[1][1] = g[1][1];
    for(int j = 2;j <= m; j++) dp[1][j] = dp[1][j - 1] + g[1][j];
    for(int i = 2; i <= n; i++) dp[i][1] = dp[i - 1][1] + g[i][1];

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++) dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + g[i][j];
    }

    cout << dp[n][m] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}