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
    vector<int> odd;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        if(x & 1) odd.push_back(x);
        else ans += x;
    }
    // cout << ans << endl;
    if(odd.empty()){cout << 0 << endl;return;}
    sort(odd.begin(),odd.end());
    int l = 0, r = odd.size() - 1;
    int stat = 0;
    while(l <= r){
        if(stat == 1) {l++;stat = 0;}
        else{
            ans += odd[r];
            stat = 1;
            r--;
        }
        // cout << stat << " " << ans << endl; 
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