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
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i & 1) ans -= a[i];
        else ans += a[i];
    }

    int base = ans;
    for(int i = 0; i < n; i++){
        ans = max(ans, base + i - (i & 1));
    }

    int mine = LLONG_MAX >> 2, mino = LLONG_MAX >> 2;

    for(int i = 0;  i < n ; i++){
        if(i & 1){
            ans = max(ans, base + i + a[i] + a[i] - mine);
            mino = min(mino,i - a[i] - a[i]);
        }
        else{
            ans = max(ans,base + i - a[i] - a[i] - mino);
            mine = min(mine,i + a[i] + a[i]);
        }

    }
    cout << ans << endl;
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