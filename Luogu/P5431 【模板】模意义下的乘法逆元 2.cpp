/*https://www.luogu.com.cn/problem/P5431*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;


int read() {
	int k = 0, f = 1;
	char c = getchar_unlocked();
	while(c < '0' || c > '9') {
		if(c == '-') f *= -1;
		c = getchar_unlocked();
	}
	while('0' <= c && c <= '9') k = k * 10 + (c - '0'), c = getchar_unlocked();
	return f * k;
}
void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + '0');
	else write(x / 10), putchar(x % 10 + '0');
}

void Exgcd(int a,int b,int &x,int &y){
    if(b == 0) x = 1, y = 0;
    else Exgcd(b,a % b,y,x), y -= a / b * x;
}

int Inv(int a,int mod){
    int x,y;
    Exgcd(a,mod,x,y);
    int res = (x % mod + mod ) % mod;
    return res;
}

int qpow(int a,int b,int mod){
    a %= mod;
    int res = 1;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n,p,k;n = read(), p = read(),k = read();
    int S = 1;
    vector<int> a(n + 1,0);
    vector<int> prod(n + 1);
    for(int i = 1; i <= n; i++){
        a[i] = read();
        prod[i] = S;
        S = (S * a[i]) % p;
    }

    S = Inv(S,p);
    int kn = qpow(k,n,p);
    int kinv = qpow(k, p - 2, p);
    int powk = kn;
    int ans = 0;

    for(int i = n; i >= 1; i--){
        int inv = (S * prod[i]) % p;
        ans = (ans + powk * inv) % p;
        S = S * a[i] % p;
        powk = powk * kinv % p;
    }

    if(ans < 0) ans += p;
    write(ans);
}

signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}