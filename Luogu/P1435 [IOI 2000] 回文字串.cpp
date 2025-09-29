/*https://www.luogu.com.cn/problem/P1435*/
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

// void solve(){
//     string s;cin >> s;
//     int n = s.size();
//     string s2 = s;
//     reverse(s2.begin(),s2.end());
//     s = " " + s;
//     s2 = " " + s2;
    
//     vii dp(n + 1,vector<int> (n + 1, 0));

//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n; j++){
//             if(s[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
//             else dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
//         }
//     }
//     int ans = n - dp[n][n];
//     cout << ans << endl;
// }

void solve(){
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}