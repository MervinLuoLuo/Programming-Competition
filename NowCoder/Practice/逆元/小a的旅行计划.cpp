/*https://ac.nowcoder.com/acm/problem/20808*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 1e8 + 7;

void Exgcd(int a,int b,int &x ,int &y){
    if(b == 0) x = 1, y = 0;
    else Exgcd(b,a % b,y,x),y -= a / b * x;
}

int Inv(int a){
    int x,y;
    Exgcd(a,MOD,x,y);
    int res = ((x % MOD) + MOD) % MOD;
    return res;
}

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

void solve(){
    int n;cin >> n;
    int inv = Inv(2);
    int p4 = qpow(4,n);
    int p3 = 3 * qpow(3,n) % MOD;
    int p2 = 3 * qpow(2,n) % MOD;
    int ans = (p4 - p3 + p2 - 1 + MOD) % MOD;
    ans = ans * inv % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}