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
    int n,rk,ck,rd,cd;
    cin >> n >> rk >> ck >> rd >> cd;
    int ans = 0;
    if(rk > rd) ans = max(ans, n - rd);
    else if(rk < rd) ans = max(ans,rd);

    if(ck > cd) ans = max(ans, n - cd);
    else if(ck < cd) ans = max(ans, cd);

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