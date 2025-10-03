/*https://www.luogu.com.cn/problem/P1775*/
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
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

    vii dp(n + 1,vector<int>(n + 1, maxn));
    for(int i = 1; i <= n; i++) dp[i][i] = 0;//合并自己的代价是 0

    for(int len = 2; len <= n; len++){
        for(int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            for(int k = l; k < r; k++){//注意不能枚举到 r
                int cost = pre[r] - pre[l - 1];
                dp[l][r] = min(dp[l][r],dp[l][k] + dp[k + 1][r] + cost);
            }
        }
    }

    cout << dp[1][n] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}