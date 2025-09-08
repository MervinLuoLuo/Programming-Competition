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
    int a,b;cin >> a >> b;
    if((a & 1) && (b & 1)) cout << a * b + 1 << endl;
    else if(!(b & 1)){
        int ans = a * b / 2 + 2;
        if(ans & 1) cout << -1 << endl;
        else cout << ans << endl;
    }
    else if(!(a & 1) && (b & 1)) cout << -1 << endl;
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