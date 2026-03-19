#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<long double> c(n + 1),p(n + 1);
    for(int i = 1; i <= n; i++){
        int x,y;cin >> x >> y;
        c[i] = x;p[i] = y / 100.0;
    }
    
    long double ans = 0;
    for(int i = n; i >= 1; i--) ans = max(ans,ans * (1-p[i]) + c[i]);

    cout << fixed << setprecision(10) << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}