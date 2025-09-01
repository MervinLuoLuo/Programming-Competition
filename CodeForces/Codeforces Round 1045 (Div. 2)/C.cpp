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
    vector<int> b(n + 1);
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        int mn = a[i];
        if (i >= 2) mn = min(mn, a[i - 1] - b[i - 2]);
        if (i + 1 < n) mn = min(mn, a[i + 1]);
        b[i] = mn;
        ans += (a[i] - b[i]);
    }
    cout << ans << endl;
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