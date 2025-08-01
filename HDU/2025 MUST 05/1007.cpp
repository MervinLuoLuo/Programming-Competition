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
const int MOD = 1e9 + 7;

int qpow(int x){
    int ans = 1;
    x %= MOD;
    int e = MOD - 2;
    while(e){
        if(e & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        e >>= 1;
    }
    return ans;
}
void solve(){
    int n,k;cin >> n >> k;
    if(k == 0) {cout << 0 << endl;return;}
    int a = (n - k + 1) % MOD;
    if(a < 0) a += MOD;
    int b = qpow(a);
    int ans = k % MOD * b % MOD;
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