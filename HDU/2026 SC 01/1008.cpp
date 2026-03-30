#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(2 * n + 2,0),pre(2 * n + 2, 0);
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        a[i] = a[n + i] = x;
    }
    // for(int i = 1; i <= 2 * n; i++) cerr << a[i] << " ";

    for(int i = 1; i <= 2 * n; i++) pre[i] = pre[i - 1] + a[i];
    int l = 1,r = 1;
    for(; l <= n; l++){
        // cerr << 1 << endl;
        while(r <= 2 * n && pre[r] - pre[l - 1] >= 0 && r - l + 1 < n) r++;
        if(r - l + 1 == n) break;
        l = r; 
    }

    if(l > n) l -= n;
    cout << l << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}