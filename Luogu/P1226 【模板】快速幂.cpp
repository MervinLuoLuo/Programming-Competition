/*https://www.luogu.com.cn/problem/P1226*/
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
int mod;

int qpow(int a,int b){
    int ans = 1;
    a %= mod;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve(){
    int a,b;cin >> a >> b >> mod;
    cout << a << "^" << b << " mod " << mod << "=" << qpow(a,b) << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}