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
    int a,b,c,d,e,f,g,h;cin >> a >> b >> c >> d >> e >> f >> g >> h;
    int sx = a + c, sy = b + d,tx = e + g,ty = f + h;
    int dx = abs(sx - tx),dy = abs(sy - ty);
    int ans = max(dx,dy);
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