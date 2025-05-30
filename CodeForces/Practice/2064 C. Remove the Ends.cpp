/*https://codeforces.com/problemset/problem/2064/C*/
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
    vector<int> prefix(n,0),suffix(n,0);
    if(a[0] > 0) prefix[0] = a[0];
    for(int i = 1;  i < n; i++){
        prefix[i] = prefix[i - 1];
        if(a[i] > 0) prefix[i] += a[i];
    }
    if(a[n - 1] < 0) suffix[n - 1] = -a[n - 1];
    for(int i = n - 2; i >= 0; i--){
        suffix[i] = suffix[i + 1];
        if(a[i] < 0) suffix[i] -= a[i];
    }
    int ans = 0;
    for(int i = 0; i <n ;i++) ans = max(ans, prefix[i] + suffix[i]);
    cout << ans << endl;
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