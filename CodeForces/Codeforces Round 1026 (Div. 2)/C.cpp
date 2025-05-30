#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "-1" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n; cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
    vector<pii> dp(n+1);
    dp[0] = {0, 0};
    //正向 dp 看区间
    for (int i = 1; i <= n; i++) {
        int curl = l[i-1], curr = r[i-1];
        pii pre = dp[i-1];
        int minH = -1, maxH = -1;
        if (d[i-1] == 0) {minH = pre.first;maxH = pre.second;}
        else if (d[i-1] == 1) {minH = pre.first + 1;maxH = pre.second + 1;} 
        else {minH = pre.first;maxH = pre.second + 1;}
        minH = max(minH, curl);
        maxH = min(maxH, curr);
        if (minH > maxH) {no;return;}
        dp[i] = {minH, maxH};
    }
    //反向贪心找策略
    vector<int> ans(n);
    int h = dp[n].first;
    for (int i = n; i >= 1; i--) {
        pii pre = dp[i-1];
        if (d[i-1] == 0) {ans[i-1] = 0;h -= 0;} 
        else if (d[i-1] == 1) {ans[i-1] = 1;h -= 1;} 
        else {
            if (h >= pre.first && h <= pre.second) ans[i - 1] = 0;
            else {ans[i-1] = 1;h -= 1;}
        }
    }

    if (h != 0) {no;return;}
    for(auto it : ans) cout << it << " ";
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}