#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 998244353;
constexpr int N = 2e5;
int fac[N + 1];

void solve(){
    int n;cin >> n;
    vector<int> a(n, 0),b(n, 0);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int ap = 0,bp = 0,maxx = 0;
    while(ap < n && bp < n){
        if(a[ap] > b[bp]) ap++,bp++,maxx++;
        else ap++;
    }
    
    int ans = 1;
    for(int i = maxx - 1; i >= 0; i--){
        int cnt = a.end() - upper_bound(a.begin(),a.end(), b[i]);
        ans = (ans * (cnt - (maxx - 1 - i))) % MOD;
    }
    
    ans = ans * fac[n - maxx] % MOD;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    fac[0] = 1;
    for(int i = 1; i <= N; i++) fac[i] = (fac[i - 1] * i) % MOD;
    while(t--){
        solve();
    }
    return 0;
}