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
    int n;cin >> n;
    int mX = -1, mx = maxn, mY = -1, my = maxn;
    for(int i = 0; i < n; i++){
        int x,y;cin >> x >> y;
        if(x > mX) mX = x;
        if(x < mx) mx = x;
        if(y > mY) mY = y;
        if(y < my) my = y;
    }
    int dx = mX - mx,dy = mY - my;
    int ans = (max(dx,dy) + 1)/ 2;
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}