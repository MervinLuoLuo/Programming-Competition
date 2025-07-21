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
    int n,x,y;cin >> n >> x >>  y;
    int cntx = __builtin_popcountll(x),cnty = __builtin_popcountll(y);
    int px = x & (-x), py = y & (-y);
    if(x == y) cout << 0 << endl;
    else if(cntx == cnty || px == py) cout << 1 << endl;
    else cout << 2 << endl;
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