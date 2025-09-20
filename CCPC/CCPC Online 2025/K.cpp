#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define vii vector<vector<int>>

void solve(){
    int n;cin >> n;
    int ans = (1 + n) * n / 2;
    cout << ans << endl;
    for(int i = n; i >= 1; i--) cout << i << " ";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}