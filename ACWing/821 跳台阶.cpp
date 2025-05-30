/*https://www.acwing.com/file_system/file/content/whole/index/content/4349/*/
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
    vector<int> dp(n + 5);
    dp[1] = 1, dp[2] = 2;
    for(int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n] << endl;
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