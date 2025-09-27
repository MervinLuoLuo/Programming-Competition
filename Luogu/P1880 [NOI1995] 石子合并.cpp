/*https://www.luogu.com.cn/problem/P1880*/
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
    vector<int> a(2 * n + 1),pre(2 * n + 2,0);
    for(int i =1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for(int i = 1; i<= 2 * n; i++) pre[i] = pre[i - 1] + a[i];

    vii dp1(2 * n + 2,vector<int>(2 * n + 2,INF));
    vii dp2(2 * n + 2,vector<int>(2 * n + 2, 0));
    for (int i = 1; i <= 2 * n; i++) dp1[i][i] = dp2[i][i] = 0;

    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len  - 1 <= 2 *n ; i++){
            int j = i + len - 1;
            for(int k = i; k < j; k++){
                int cost = pre[j] - pre[i - 1];
                dp1[i][j] = min(dp1[i][j],dp1[i][k] + dp1[k+ 1][j] + cost);
                dp2[i][j] = max(dp2[i][j],dp2[i][k] + dp2[k + 1][j] + cost);
            }   
        }
    }
    int ansmin = INF ,ansmax = 0;
    for(int i = 1; i <= n; i++){
        ansmin = min(ansmin,dp1[i][i + n - 1]);
        ansmax = max(ansmax,dp2[i][i + n - 1]);
    }
    cout << ansmin << endl << ansmax << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}