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
    if(n == 1){cout << 1 << endl;return;}
    vector<int> pre(n),suf(n);
    pre[0] = a[0];
    suf[n - 1] = a[n - 1];
    for(int i = 1; i < n ;i++) pre[i] = min(a[i],pre[i - 1]);
    for(int i = n - 2;i >= 0; i--) suf[i] = max(suf[i + 1], a[i]);

    for(int i = 0;i < n ;i++){
        int premin = (i == 0) ? maxn : pre[i - 1];
        int sufmax = (i == n - 1 ) ? -1 : suf[i + 1];
        if(a[i] < premin || a[i] > sufmax) cout << 1;
        else cout << 0;
    }
    cout << endl;
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