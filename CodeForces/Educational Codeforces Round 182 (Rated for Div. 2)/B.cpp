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
    vector<int> a(n + 1,0),vis(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != 0) vis[a[i]] = 1;
    }

    int cur = n;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            while(vis[cur] && cur > 0) cur--;
            a[i] = cur--;
        }
    }

    vector<int> b = a;
    sort(b.begin(),b.end());

    int l = 1;
    while(l <= n && a[l] == b[l])l++;
    if(l > n){cout << 0 << endl;}
    else{
        int r = n;
        while(r >= 1 && a[r] == b[r]) r--;
        cout << r - l + 1 << endl;
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