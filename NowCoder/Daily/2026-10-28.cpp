#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    VII v(n + 1),w(n + 1);
    int maxn = 0;
    for(int i = 1; i <= n;i ++){
        int a,b,c;cin >> a >> b >> c;
        w[c].push_back(a);
        v[c].push_back(b);
        maxn = max(maxn,c);
    }
    vector<int> dp(m + 1);
    for(int i = 1; i <= maxn; i++){
        for(int j = m; j >= 0; j--){
            for(int k = 0; k < v[i].size(); k++){
                if(w[i][k] <= j) dp[j] = max(dp[j],dp[j - w[i][k]] + v[i][k]);
            }
        }
    }

    cout << dp[m] << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}