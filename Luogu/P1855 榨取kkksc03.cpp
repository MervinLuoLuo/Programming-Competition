/*https://www.luogu.com.cn/problem/P1855*/
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
    int n,M,T;cin >> n >> M >> T;
    vector<int> m(n+ 1),t(n + 1);
    for(int i = 1; i <= n; i++) cin >> m[i] >> t[i];

    vii dp(M + 1,vector<int>(T + 1, 0));

    for(int k = 1; k <= n; k++){
        for(int i = M; i >= m[k]; i--){
            for(int j = T; j >= t[k]; j--){
                dp[i][j] = max(dp[i][j],dp[i - m[k]][j - t[k]] + 1);
            }
        }
    }

    cout << dp[M][T] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}