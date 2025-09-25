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
    int n,m;cin >> n >> m;
    vector<int> a(m);
    for(int &x : a) cin >> x;
    if(!is_sorted(a.begin(),a.end())){
        cout << 1 << endl;
        return;
    }
    if(a.size() == 2 && a[0] == 1 && a[1] == 1) {cout << 1 << endl;return;}
    else if(a.size() == 3 && a[0] == 1 && a[1] == 1 && a[2] == 2) {cout << 1 << endl;return;}
    int ans = n - a[m - 1] + 1;
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