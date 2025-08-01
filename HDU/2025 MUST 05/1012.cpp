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
    vector<int> a(n),b(n);
    for(int & x : a) cin >> x;    
    for(int & x : b) cin >> x;
    vector<int> f1(n),f2(n);
    for(int i = 0; i < n; i++){
        f1[i] = a[i] - b[i];
        f2[i] = a[i] + b[i];
    }
    int ans = INF;
    sort(f1.begin(),f1.end());
    for(int i = 1; i < n; i++) ans = min(ans, f1[i] - f1[i - 1]);
    sort(f2.begin(),f2.end());
    for(int i = 1; i < n; i++) ans = min(ans,f2[i] - f2[i - 1]);
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