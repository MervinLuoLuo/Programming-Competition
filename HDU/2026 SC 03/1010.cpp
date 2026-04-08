#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 998244353;
int fac[5005],inv[5005];

int qpow(int a,int e){
    int res = 1;
    a = a % MOD;
    while(e){
        if(e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

void ini(){
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 5000;i ++) fac[i] = fac[i - 1] * i % MOD; 
    inv[5000] = qpow(fac[5000],MOD - 2);
    for(int i = 4999; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int C(int x,int y){
    if(x < 0 || y < 0 || x < y) return 0;
    int res = ((fac[x] * inv[y]) % MOD * inv[x - y]) % MOD;
    return res;
}

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    sort(a.begin() + 1,a.end());
    for(int i = 2; i <= n;i++){
        int d = min(a[1],a[i] - a[i - 1]);
        ans = (ans + C(a[i],d)) % MOD;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    ini();
    while(t--){
        solve();
    }
    return 0;
}