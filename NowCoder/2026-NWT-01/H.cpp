#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 998244353;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1, 0),pre(n + 1, 0);
    int last = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = last;
        if(a[i] > 0) last = i;
    }
    
    vector<int> dp(n + 2,0),s(n + 2,0);
    dp[1] = s[1] = 1;
    for(int i = 1; i <= n; i++){
        int j = i,val = 0;
        while(j > 0 && (val & a[j]) == 0) {
            val |= a[j];
            j = pre[j];
        }
        dp[i + 1] = (s[i] - s[j] + MOD) % MOD;
        s[i + 1] = (s[i] + dp[i + 1]) % MOD;
    }

    cout << dp[n + 1] << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}