/*LCS*/
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
    string A,B;cin >> A >> B;
    int n = A.size(),m = B.size();
    vector<int> a(n + 1),b(m + 1);
    A = " " + A;B = " " + B;
    for(int i = 1; i <= n; i++){
        a[i] = A[i] - 'a';
    }
    for(int i = 1; i <= m; i++) b[i] = B[i] - 'a';

    vii dp(n + 1,vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
        }
    }

    cout << dp[n][m] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}