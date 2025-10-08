/*https://codeforces.com/problemset/problem/2050/E*/
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
    string a,b,c;cin >> a >> b >> c;
    int n = a.size(),m = b.size();
    int dp[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) dp[i][j] = maxn;
    }

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + (a[i - 1] != c[i - 1]);
    for(int j = 1; j <= m; j++) dp[0][j] = dp[0][j - 1] + (b[j - 1] != c[j - 1]);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = min(
                        dp[i - 1][j] + (a[i - 1] != c[i + j - 1]),
                        dp[i][j - 1] + (b[j - 1] != c[i + j - 1])
                        );
        }
    }

    cout << dp[n][m] << endl;
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