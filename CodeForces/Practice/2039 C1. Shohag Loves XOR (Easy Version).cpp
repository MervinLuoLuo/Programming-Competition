/*https://codeforces.com/problemset/problem/2039/C1*/
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
    int x,m;cin >> x >> m;
    int ans = 0;
    for(int y = 1;y <= min(2LL * x, m); y++){
        if(y != x && ((x % (x ^ y)) == 0 || (y % (x ^ y)) == 0)) ans++;
    }
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