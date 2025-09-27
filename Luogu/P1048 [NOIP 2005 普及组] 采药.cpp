/*https://www.luogu.com.cn/problem/P1048*/
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
    int n,m;cin >> m >> n;
    vector<int> w(n + 1),val(n + 1);
    for(int i = 1; i <= n; i++) cin >> w[i] >> val[i];

    vector<int> dp(m + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= w[i]; j--){
            dp[j] = max(dp[j],dp[j - w[i]] + val[i]);
        }
    }

    cout << dp[m] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}