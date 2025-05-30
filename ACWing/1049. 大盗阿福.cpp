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
    int n;cin >> n;
    vector<int> val(n + 5);
    for(int i = 1 ; i <= n; i++) cin >> val[i];
    vector<int> dp(n + 5);
    dp[1] = val[1];
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + val[i]);
    }
    cout << dp[n] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}