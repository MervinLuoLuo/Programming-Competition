//https://codeforces.com/problemset/problem/1982/B
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

void solve(){
    int x,y,k;cin >> x >> y >> k;
    while(k > 0 && x != 1){
        int cnt = (x / y + 1) * y - x;
        cnt = max(1LL,cnt);
        cnt = min(cnt,k);
        x += cnt;
        while(x % y == 0) x /= y;
        k -= cnt;
    }
    int ans = x + (k % (y - 1));
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