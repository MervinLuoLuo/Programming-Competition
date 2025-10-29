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
    vector<int> a(n + 1,0);
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = max(pre[i - 1],a[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i += 2){
        int diff = -1;
        if(i > 1) diff = max(diff, a[i] - pre[i - 1]);
        if(i < n) diff = max(diff, a[i] - pre[i + 1]);
        ans += diff + 1;
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