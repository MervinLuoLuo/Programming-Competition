#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
const int MOD = 998244353;

int mul(int a, int b) {
    return a % MOD * (b % MOD) % MOD;
}

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n ;i++) cin >> a[i];

    int sum = 0;
    int minP = INF, maxP = -INF;
    int lp = -1, rp = -1;
    for(int i = 1; i <= n; i++){
        if(a[i] > 0){
            sum += a[i];
            minP = min(minP,a[i]);
            maxP = max(maxP,a[i]);
            if(lp == -1) lp = i;
            rp = i;
        }
    }

    if(lp == -1){
        int cnt = n * (n + 1) / 2 % MOD;
        int win = (n + 1) * (n + 1) % MOD;
        int ans = mul(cnt,win);
        cout << 0 << " " << ans << endl;
    }
    else{
        int cnt = lp * (n - rp + 1) % MOD;
        int win = (minP + n + 1) * (n - maxP + 1) % MOD;
        int ans = mul(cnt,win);
        cout << sum << " " << ans << endl;
    }
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