#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<pair<string,int>> se;
    for(int i = 0; i < n; i++){
        if(se.empty() or  se.back().first != a[i]) se.push_back({a[i],1});
        else se.back().second++;
    }
    int ans = 0;
    for(auto it : se) ans= max(ans,it.second);
    for(int i = 0; i + 2 < se.size(); i++){
        if(se[i].first == se[i + 2].first and se[i + 1].second == 1) ans = max(ans,se[i].second + se[i + 2].second);
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}