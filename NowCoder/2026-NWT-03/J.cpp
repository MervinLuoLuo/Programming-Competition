#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
using ull = unsigned long long;

void solve(){
    int n,q;cin >> n >> q;
    int h = bit_width((ull) n);
    while(q--){
        int x;cin >> x;
        int d = bit_width((ull)x);
        int ans = 0;
        if(d < h) ans = 1ll << (d - 1);
        else ans = n - ((1ll << (h - 1)) - 1);
        cout << ans << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}