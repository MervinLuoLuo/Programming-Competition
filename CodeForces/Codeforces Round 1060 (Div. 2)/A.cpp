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
    int n,k;cin >> n >> k;
    string s;cin >> s;
    s = " " + s;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n ; i++){
        a[i] = s[i] - '0';
    }
    vector<int> pre(n + 1,0);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }

    int ans = (a[1] == 1 ? 1 : 0);
    for(int i = 2; i <= n; i++){
        if(a[i] == 0) continue;
        int l = max(i - k, 0LL), r = i - 1;
        if(pre[r] - pre[l] == 0) ans++;
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