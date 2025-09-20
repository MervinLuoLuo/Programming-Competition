#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define vii vector<vector<int>>

void solve(){
    int n,m;cin >> n >> m;
    int ans = 2 * (m - ((n + 1) / 2)) + 1;
    if(n == m) ans = m;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}