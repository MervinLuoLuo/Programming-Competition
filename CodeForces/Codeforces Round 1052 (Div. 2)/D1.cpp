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
    int l,r;cin >> l >> r;
    int pw = 1,ans = 0;
    
    //初始化 pw
    while(pw < r) pw = pw << 1 | 1;

    vector<int> vis(r + 1, 0);
    vector<int> a(r + 1, 0);
    for(int i = r; i >= l; i--){
        while(pw - i > r || pw - i < l||vis[pw - i]) pw >>= 1;
        a[i] = pw - i;
        ans += (a[i] | i);
        vis[pw - i] = 1;
    }

    cout << ans << endl;
    for(int i = l; i <= r; i++) cout << a[i] << " ";
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}