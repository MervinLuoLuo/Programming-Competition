/*https://www.luogu.com.cn/problem/P1757*/
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
    vii g(101);
    int maxg = 0;
    vector<int> w(n + 1),val(n + 1);
    for(int i = 1; i <= n;i++){
        int k;cin >> w[i] >> val[i] >> k;
        g[k].push_back(i);
        maxg = max(maxg, k);
    }

    vector<int> dp(m + 1);
    for(int gr = 1; gr <= maxg; gr++){
        for(int j = m; j >= 0; j--){
            for(int i = 0; i < g[gr].size();i++){
                int cur = g[gr][i];
                if(j >= w[cur]) dp[j] = max(dp[j],dp[j - w[cur]] + val[cur]);
            }
        }
    }

    cout << dp[m] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}