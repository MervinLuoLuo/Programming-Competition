/*https://codeforces.com/problemset/problem/2059/B*/
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
    vector<int> a(n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n == k){
        int ans = 1;
        for(int i = 2; i <= n; i += 2,ans++){
            if(a[i] != ans) {cout << ans << endl;return;}
        }
        cout << ans << endl;return;
    }

    if(k == 2){
        for(int i = n; i >= 2; i--){
            if(a[i] != 1) {cout << 1 << endl;return;}
        }
        cout << 2 << endl;
    }
    else{
        for(int i = 2; i <= n - k + 2; i++){
            if(a[i] != 1){cout << 1 << endl;return;}
        }
        cout << 2 << endl;
    }
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