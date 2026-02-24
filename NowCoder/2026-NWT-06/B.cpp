#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e7;
constexpr int MOD = 998244353;

vector<int> fac(MAXN + 1),inv(MAXN + 1);
int qpow(int a,int b){
    int res = 1;
    a %= MOD;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int calc(int n,int k){
    if(k < 0 || k > n) return 0;
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int com(int x,int k){
    if(k == 0) return (x == 0) ? 1 : 0;
    if(x < k) return 0;
    return calc(x - 1,k - 1);
}

void solve(){
    int n,x,t;cin >> n >> x >> t;
    int r = t + 1;
    int cnt = n - x;
    
    int a1 = (r + 1) / 2,b1 = r / 2;
    int res1 = com(x, a1) * com(cnt,b1) % MOD;

    int a0 = r / 2,b0 = (r + 1) / 2;
    int res2 = com(x,a0) * com(cnt,b0) % MOD;
    int ans = (res1 + res2) % MOD;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    fac[0] = 1;
    for(int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
    inv[MAXN] = qpow(fac[MAXN],MOD - 2);
    for(int i = MAXN; i >= 1; i--) inv[i - 1] = inv[i] * i % MOD;
    while(t--){
        solve();
    }
    return 0;
}