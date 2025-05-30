/*https://www.luogu.com.cn/problem/P1048*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,t;cin >> n >>t;
    vector<int> time(n+ 5),val(n + 5);
    for(int i = 1; i <= n;i++){
        cin >> time[i] >> val[i];
    }
    vector<vector<int>> dp(1005);
    for(int i = 1; i <= n; i++){
        for(int j = t; j >= 0; j--){
            if(j > time[i]){
                dp[i][j] = max(dp[i - 1][j-time[i]] + val[i],dp[i - 1][j]);
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][t] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}