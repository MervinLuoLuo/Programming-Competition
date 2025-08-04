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
    vector<int> a,b;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        if(x < 0) a.push_back(x);
        if(x == 0) ans++;
        if(x > 0) b.push_back(x);
    }

    if(!a.empty() && a.size() & 1 && ans == 0){
        int x = INF;
        if(!b.empty()) x = *min_element(b.begin(),b.end());
        int y = *max_element(a.begin(),a.end());
        int xx = x + 1, yy = 1 - y;
        ans += min(xx,yy);
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