/*https://codeforces.com/problemset/problem/2005/B2*/
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
    int n,m,q;cin >> n >> m >> q;
    vector<int> a(m);
    for(int &x : a) cin >> x;
    sort(a.begin(),a.end());

    while(q--){
        int p;cin >> p;
        int right = upper_bound(a.begin(),a.end(),p) - a.begin();
        if(right == 0) cout << a[0] - 1 << endl;
        else if(right == m) cout << n - a[m - 1] << endl;
        else cout << ((a[right] - a[right - 1]) >> 1) << endl;
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