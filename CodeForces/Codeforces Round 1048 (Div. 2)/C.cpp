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
    int k,x;cin >> k >> x;
    int kk = 111 << k;
    int y = kk * 2 - x;
    if(x == 0 || x == 2 * kk){cout << -1 << endl;return;}

    vector<int> ans;
    while(x != kk){
        if(x > y) {
            ans.push_back(2);
            x -= y;y *= 2;
        }
        else{
            ans.push_back(1);
            y -= x;x *= 2;
        }
    }

    cout << ans.size() << endl;
    for(auto it : ans) cout << it << " ";
    cout << endl;
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