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
    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(),a.end());
    int ans = 0;

    for(int z = 0; z < n;z++){
        for(int y = 0; y < z; y++){
            int need = max(a[n - 1], 2 * a[z]) - a[y] - a[z];
            int x = upper_bound(a.begin(),a.begin() + y, need) - a.begin();
            ans += y - x;
        }
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