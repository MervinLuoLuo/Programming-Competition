#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 998244353;
int n;
vector<int> fac,inv;

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
    fac.assign(n + 1, 0);inv.assign(n + 1, 0);
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    inv[n] = qpow(fac[n],MOD - 2);
    for(int i = n - 1; i >= 0; i--) inv[i] = (i + 1) * inv[i + 1] % MOD;
    
}

int C(int x,int y){
    if(x < 0 || y < 0 || x < y) return 0;
    int res = ((fac[x] * inv[y] % MOD) * inv[x - y]) % MOD;
    return res % MOD;
}

void solve(){
    cin >> n;
    ini();
    int ans = 0;
    for(int i = 1; i <= (n + 1) / 2; i++){
        ans = (ans + ((C(n - i,i - 1) * fac[i - 1] % MOD) * fac[n - i] % MOD)) % MOD;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}