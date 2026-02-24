#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 2048;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1,0),b(n + 1,0);
    for(int i = 1; i <= n ;i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    vector<int> dp(MAXN,0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        vector<int> ndp(MAXN,0);
        for(int j = 0; j < MAXN; j++){
            if(!dp[j]) continue;

            int v1 = max(0ll,j - a[i]);
            ndp[v1] = 1;

            int v2 = j ^ b[i];
            ndp[v2] = 1;
        }
        dp = ndp;
    }

    for(int v = MAXN - 1;v > 0; v--){
        if(dp[v]){
            cout << v << endl;
            return;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}