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
    string s;cin >> s;
    vector<int> a(n + 1,0);
    s = " " + s;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'a') a[i] = -1;
        else a[i] = 1; 
    }
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) pre[i] = a[i] + pre[i - 1];

    int need = pre[n];

    vector<int> l(2 * n + 1, -n);
    int ans = n;
    l[pre[0] + n] = 0;
    for(int i = 1; i <= n; i++){
        l[pre[i] + n] = max(l[pre[i] + n],i);
        int cl = l[pre[i] - need + n];
        ans = min(ans,i - cl);
    }

    if(ans == n) cout << -1 << endl;
    else cout << ans << endl;

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