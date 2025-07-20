#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
const int mod = 998244353;

void solve(){
    int n;cin>> n;
    vector<int> a(n + 1);a[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int cnt0 = 0,cnt1 = 0,cnt2 = 0;

    for(int i = 0 ; i < n; i++){
        if(a[i] == 0 && a[i + 1] == 1) cnt0++;
        if(a[i] == -1 && a[i + 1] == 1) cnt1++;
        if(a[i] == 0 && a[i + 1] == -1) cnt1++;
        if(a[i] == -1 && a[i + 1] == -1) cnt2++;
    }

    int rev = ((mod + 1) >> 1);
    int rev_ = rev * rev % mod;

    int ans = cnt0;
    ans += rev * cnt1 % mod;
    ans %= mod;
    ans += rev_ * cnt2 % mod;
    ans %= mod;

    for(int i = 0; i <= n; i++){
        if(a[i] == -1){
            ans *= 2;
            if(ans >= mod) ans -= mod;
        }
    }
    cout << ans << endl;
    
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