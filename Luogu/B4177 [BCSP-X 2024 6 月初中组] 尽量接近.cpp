/*https://www.luogu.com.cn/problem/B4177*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int sum = accumulate(a.begin() + 1,a.end(),0ll);
    VII dp(n + 1,vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(j < a[i]){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - a[i]];
            }
        }
    }
    int ans = 0,dif = INF;
    for(int i = 1; i <= sum; i++){
        if(dp[n][i] && abs(i - k) < dif || i < ans){
            ans = i;
            dif = abs(i - k);
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}