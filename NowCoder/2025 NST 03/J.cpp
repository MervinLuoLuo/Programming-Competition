#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int v2(int n) {
    return n ? __builtin_ctzll(n) : 0;
}

void solve(){
    int x, y;
    cin >> x >> y;
    if (x == 0 || y == 0) {
        cout << 0 << endl;
        return;
    }
    int S = x + y;
    if (S & 1) {
        cout << -1 << endl;
        return;
    }
    int k = v2(S);
    int m = S >> k;
    if (x % m != 0) {
        cout << -1 << endl;
        return;
    }
    int ans = k - v2(x);
    cout << ans << endl;
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
