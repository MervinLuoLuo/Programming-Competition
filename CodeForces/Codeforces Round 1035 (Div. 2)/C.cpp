#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,l,r,k;cin >> n >> l >> r >> k;
    if(n & 1) {cout  << l << endl;return;}
    if(n == 2){cout << -1 << endl;return;}
    int res = 1;
    bool flag = 0;
    while(res <= r){
        if(res > l){
            flag = 1;
            if(k <= n - 2) cout << l << endl;
            else cout << res << endl;
            break;
        }
        res *= 2;
    }
    if(!flag) cout << -1 << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}