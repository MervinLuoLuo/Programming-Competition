#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e9;
constexpr double e = 10-10;

void solve(){
    int n,m;cin >> n >> m;
    vector<tuple<int,int,int>> a(n + 1);
    for(int i = 1; i <= n; i++){
        int p,v,w;cin >> p >> v >> w;
        a[i] = {v,p,w};
    }
    vector<double> dp(m + 1, -INF);
    dp[0] = 0.0;

    sort(a.begin() + 1,a.end());
    for(auto &[v,p,w] : a){
        double x = p / 100.0;
        double y = 1.0 - x;
        double val = x * v;
        for(int j = m; j >= w; j--){
            double cand = val + y * dp[j - w];
            dp[j] = max(cand,dp[j]);
        }
    }

    double ans = *max_element(dp.begin(),dp.end());
    cout << fixed << setprecision(10) << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    srand(time(0));
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}