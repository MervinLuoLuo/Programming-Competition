#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e6;
constexpr int MOD = 1e9 + 7;
int fac[MAXN + 5],inv[MAXN + 5];
string s;

int qpow(int a,int e){
    int res = 1;
    a %= MOD;
    while(e){
        if(e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

void ini(){
    fac[0] = fac[1] = 1;
    for(int i = 2 ; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
    inv[MAXN] = qpow(fac[MAXN],MOD - 2) % MOD;
    for(int i = MAXN - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int C(int n,int m){
    if(n == 0 || m == 0 || n == m) return 1;
    int res = fac[n] % MOD;
    res = res * inv[m] % MOD;
    res = res * inv[n - m] % MOD;
    return res;
}

void solve(){
    int cur = 0;
    int cnt1 = 0,cnt2 = 0;
    int len = s.size();
    for(int i = 0; i < len; i++){
        if(s[i] == '?'){
            if(((len - 1) & i) == i) cnt1++;
            else cnt2++;
        }
        else{
            if(((len - 1) & i) == i) cur ^= (s[i] - '0');
        }
    }
    if(cnt1 == 0){
        if(cur == 0) cout << 0 << endl;
        else{
            int ans = qpow(2,cnt2) % MOD;
            cout << ans << endl;
        }
    }
    else{
        int L = 0,R = 0;
        if(cnt2 != 0) R = qpow(2,cnt2);
        if(cur == 0){
            for(int i = 1; i <= cnt1; i += 2) L = (L + (C(cnt1,i) % MOD)) % MOD;
        }
        else{
            for(int i = 0; i <= cnt1; i += 2) L = (L + (C(cnt1,i) % MOD)) % MOD;
        }
        int ans = L % MOD;
        if(R != 0) ans = ans * R % MOD;
        cout << ans << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ini();
    while(cin >> s)
    solve();
    return 0;
}