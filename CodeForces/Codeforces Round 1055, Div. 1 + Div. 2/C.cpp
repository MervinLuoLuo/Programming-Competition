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
    int n,q;cin >> n >> q;
    vector<int> a(n);
    vector<int> pre0(n),pre1(n);
    vector<int> adj(n,0),preadj(n,0);
    for(int &x : a) cin >> x;
    pre0[0] = (a[0] == 0);
    pre1[0] = (a[0] == 1);
    adj[0] = preadj[0] = 0;
    for(int i = 1; i < n; i++){
        pre0[i] = pre0[i - 1] +(a[i] == 0);
        pre1[i] = pre1[i - 1] + (a[i] == 1);
        adj[i] = (a[i - 1] == a[i]);
        preadj[i] = preadj[i - 1] + adj[i];  
    }

    while(q--){
        int l,r;cin >> l >> r;
        l--,r--;
        int cnt0 = pre0[r] - (l ? pre0[l - 1] : 0);
        int cnt1 = pre1[r] - (l ? pre1[l - 1] : 0);
        if(cnt0 % 3 || cnt1 % 3) {cout << -1 << endl;continue;}

        int ans = 2 + (r - l -2 ) / 3;
        if(preadj[r] - preadj[l] > 0) ans = (r - l + 1) / 3;
        cout << ans << endl;
    }
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