#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 676767677;

void solve(){
    int x,y;cin >> x >> y;
    int l = abs(x - y);
    int ans = 0;
    for(int i = 1; i <= l + 1; i++){
        if(l % i == 0) ans = (ans + 1) % MOD;
    }
    if(l == 0) ans = 1;
    cout << ans % MOD << endl;

    for(int i = 1; i <= x; i++) cout << 1 << " ";
    for(int i = 1; i <= y; i++) cout << -1 << " ";
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}