#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,q;cin >> n >> q;
    vector<ll> a(n + 5), diff(n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) diff[i] = a[i] - a[i - 1];
    while(q--){
        int l,r,x;cin >> l >> r >> x;
        diff[l] += x;
        diff[r + 1] -= x;
    }
    for(int i = 1; i <= n; i++) a[i] = diff[i] + a[i - 1];
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}