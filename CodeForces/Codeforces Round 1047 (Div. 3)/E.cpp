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
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    if(k > 1) k = k % 2 + 2;

    for(int i = 0; i< k; i++){
        vector<int> vis(n + 1,0);
        for(int i = 0; i < n; i++) vis[a[i]]++;

        // 找MEX
        int MEX = -1;
        for(int j = 0; j <= n; j++){
            if(!vis[j]){
                MEX = j;
                break;
            }
        }

        for(int j = 0; j < n; j++){
            if(vis[a[j]] == 1) a[j] = min(a[j],MEX);
            else a[j] = MEX;
        }
    }

    int ans = accumulate(a.begin(),a.end(),0LL);
    cout << ans << endl;
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