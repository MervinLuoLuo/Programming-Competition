#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1, 0),pre(n + 1, 0);
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(mp[a[i]] != 0) pre[i] = mp[a[i]];
        else pre[i] = 0;
        mp[a[i]] = i;
    }
    // for(int i = 1; i <= n; i++) cerr << pre[i] << " ";
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int res = (i - pre[i]) * (1 + n - i + 1) * (n - i + 1) / 2;
        ans += res;
    }
    cout << ans << endl;    
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}