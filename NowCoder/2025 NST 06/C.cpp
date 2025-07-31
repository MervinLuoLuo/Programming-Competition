#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 5e5;
const int MOD = 998244353;

vector<int> fac, invv, H1, H2, H3;

int add(int a,int b){ 
    a += b;
    if(a >= MOD) a-= MOD;
    return a;
}

int Sub(int a,int b){
    a -= b;
    if(a < 0) a += MOD;
    return a;
}

int mul(int a,int b) {return (int)a * b % MOD;}
void init(){
    fac.assign(maxn+1, 0);
    invv.assign(maxn+1, 0);
    H1.assign(maxn+1, 0);
    H2.assign(maxn+1, 0);
    H3.assign(maxn+1, 0);

    fac[0] = 1;
    for(int i = 1; i <= maxn; i++) fac[i] = mul(fac[i - 1],i);

    invv[1] = 1;
    for(int i = 2; i <= maxn; i++) invv[i] = mul(MOD - MOD/i, invv[MOD % i]);

    for(int i = 1; i <= maxn; i++){
        int i1 = invv[i];
        int i2 = mul(i1,i1);
        int i3 = mul(i2,i1);
        H1[i] = add(H1[i - 1],i1);
        H2[i] = add(H2[i-1], i2);
        H3[i] = add(H3[i-1], i3);
    }
}

void solve(){
    int n;cin >> n;
    int h1 = H1[n],h2 = H2[n],h3 = H3[n];
    int t1 = mul(mul(h1,h1),h1);
    int t2 = mul(3,mul(h1,h1));
    int t3 = h1;
    int t4 = mul(3,mul(h1,h2));
    int t5 = mul(3,h2);
    int t6 = mul(2,h3);
    int E3 = add(Sub(add(add(t1,t2),t3),add(t4,t5)),t6);
    int ans = mul(fac[n],E3);
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    init();
    while(t--){
        solve();
    }
    return 0;
}