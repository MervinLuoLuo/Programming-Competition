#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 998244353;

int calc(int x){
    int res = 1;
    for(int i = 1; i <= x; i++) res = (res * i) % MOD;
    return res;
}

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1, 0),b(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    int minb = *min_element(b.begin() + 1,b.end());

    int l = 0;
    for(int i = 1; i <= n; i++) l += a[i] > minb;
    int r = n - l;
    int ans = (calc(l) * calc(r)) % MOD;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}