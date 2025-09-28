/*https://www.luogu.com.cn/problem/P2858*/
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
    int n;cin >> n;
    vector<int> val(n + 1);
    for(int i = 1; i <= n; i++) cin >> val[i];

    vii dp(n + 1,vector<int>(n + 1,0));
    for(int i =1; i <= n; i++) dp[i][i] = val[i] * n;

    for(int len = 2; len <= n; len++){
        for(int l = 1; l <= n; l++){
            int r = l + len - 1;
            if(r > n) break;
            dp[l][r] = max(dp[l + 1][r] + val[l] * (n - len + 1),dp[l][r - 1] + val[r] * (n - len + 1));
        }
    }
    cout << dp[1][n] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}