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
    int n,m;cin >> n >> m;
    int ans = 0;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    int stat = 0;
    if(a[0] & 1){
        if(b[0] != stat) {ans += a[0];stat = 1;}
        else ans += a[0] - 1;
    }
    else{
        if(b[0] != stat) {ans += a[0] - 1;stat = 1;}
        else ans += a[0];
    }

    for(int i = 1;i < n; i++){
        if((a[i] - a[i - 1]) & 1){
            if(b[i] != stat){ans += a[i] - a[i - 1];stat = (stat == 0 ? 1 : 0);}
            else ans += a[i] - a[i - 1] - 1;
        }
        else{
            if(b[i] != stat) {ans += a[i] - a[i - 1] - 1;stat = (stat == 0 ? 1 : 0);}
            else ans += a[i] - a[i - 1];
        }
    }
    if(a[n - 1] != m) ans += m - a[n - 1];
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