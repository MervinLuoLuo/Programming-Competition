/*https://codeforces.com/contest/2096/problem/B*/
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
    vector<int> l(n),r(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < n; i++) cin >> r[i];
    vector<int> a(n);
    int ans = 0, need = k - 1;
    for(int i = 0; i < n; i++){
        ans += max(l[i],r[i]);
        a[i] = min(l[i],r[i]);
    }
    sort(a.begin(),a.end(),greater<>());
    for(int i = 0; i < need; i++) ans += a[i];
    cout << ans + 1 << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}