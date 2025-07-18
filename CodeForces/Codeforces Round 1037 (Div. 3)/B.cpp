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
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1) continue;
        int r = i;
        while(r < n && r - i + 1 < k  && a[r] == 0) r++;
        if(r - i + 1 == k && r < n && a[r] == 0) {ans++;i = r + 1;}
        else i = r;
        // cout << ans << endl;
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