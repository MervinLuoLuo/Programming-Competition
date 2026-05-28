#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MOD = 998244353;
int n,m;
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

int add(int x,int y){
    x %= MOD;y %= MOD;
    int res = (x + y) % MOD;
    return res;
}

void solve(){
    cin >> n >> m;
    
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}