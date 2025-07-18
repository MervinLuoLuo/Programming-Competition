#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> h;
    for(int i  = 1; i <= n; i++){
        if(a[i] >= a[k]) h.push_back(a[i]);
    }
    sort(h.begin(),h.end());
    // for(auto it : h) cout << it << " ";
    int cur = h[0];
    bool flag = 1;
    int t = 1;
    for(int i = 0; i < h.size(); i++){
        if(h[i] == cur) continue;
        int dif = h[i] - cur;
        t += dif;
        if(dif != 1){
            if(t - 1 > cur){flag = 0;break;}
        }
        // cout << flag << endl;
        // if(t > cur) {flag = 0;break;}
        cur = h[i];
        // cout << cur << " ";
    }
    if(flag) yes;
    else no;
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