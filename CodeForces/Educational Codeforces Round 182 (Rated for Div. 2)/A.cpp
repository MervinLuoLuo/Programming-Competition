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
    vector<int> a(n + 1, 0),pre(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for(int l = 1; l <= n; l++){
        for(int r = l + 1; r <= n - 1; r++){
            int res1 = pre[l] % 3;
            int res2 = (pre[r] - pre[l]) % 3;
            int res3 = (pre[n] - pre[r]) % 3;
            if((res1 == res2 && res2 == res3) || (res1 != res2 && res2 != res3 && res1 != res3)){
                // cout << l << " " << r << " " << res1 << " " << res2 << " " << res3 << endl;
                // return;
                cout << l << " " << r << endl;
                return;
            }
        }
    }
    cout << "0 0" << endl;
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