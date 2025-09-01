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
    vector<int> dp(n + 1);
    dp[1] = 1;
    for(int i = 2, i2 = 1,i3 = 1,i5 = 1, a, b, c, cur; i <= n; i++){
        a = dp[i2] * 2;
        b = dp[i3] *  3;
        c = dp[i5] * 5;
        cur = min(a,min(b,c));
        if(cur == a) i2++;
        if(cur == b) i3++;
        if(cur == c) i5++;
        dp[i] = cur;
    }
    cout << dp[n] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}