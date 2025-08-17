/*https://codeforces.com/problemset/problem/1982/C*/
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
    int n,l,r;cin >> n >> l >> r;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int ans= 0;
    int sum = 0;
    int L = 0, R = 0;
    while(L < n){
        while(R < n && sum < l) {sum += a[R];R++;}
        if(sum >= l && sum <= r){ans++;L = R;sum = 0;}
        else{sum -= a[L]; L++;}
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