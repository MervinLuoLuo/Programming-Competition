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
    map<int,int> freq;
    vector<int> vis, ivis;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        freq[x]++;
    }

    int cnt = 0;
    for(auto [u,v] : freq){
        cnt += u * (v / 2);
        if(v & 1) ivis.push_back(u);
        else if(v >= 2) vis.push_back(u);
    }

    if(cnt == 0) {cout << 0 << endl;return;}

    int ans = 0;
    for(int x : ivis){
        if(2 * cnt > x) ans = max(ans, 2 * cnt + x);
    }

    for(int i = 1; i < ivis.size(); i++){
        if(ivis[i - 1] + 2 * cnt > ivis[i]) ans = max(ans,2 * cnt + ivis[i - 1] + ivis[i]);
    }

    for(int x : vis){
        if(cnt - x > 0) ans = max(ans, 2 * cnt);
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