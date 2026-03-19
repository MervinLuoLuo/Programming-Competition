/*https://ac.nowcoder.com/acm/contest/24213/1001*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1,dp[2] = 2;
    for(int i = 3; i <= n ;i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}