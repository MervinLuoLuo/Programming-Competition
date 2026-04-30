#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 1e9 + 7;
int p,q,r;
int n;
vector<int> a;
int fac[MAXN + 1],inv[MAXN + 1];

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
    for(int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
    inv[MAXN] = qpow(MAXN,MOD - 2) % MOD;
    for(int i = MAXN - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

void solve(){
    cin >> p >> q >> r;
    cin >> n;
    a.assign(n + 1,0);
    for(int i = 1; i <= n; i++) cin >> a[i];

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ini();
    solve();
    return 0;
}