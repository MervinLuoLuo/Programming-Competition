#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++){
        bool flag = 0;
        for(int j = i + 1; j < n; j++){
            if(((a[j] % a[i]) & 1) == 0){
                ans1 = a[i], ans2 = a[j];
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    if(ans1 == 0 && ans2 == 0) cout << -1 << endl;
    else cout << ans1 << " " << ans2 << endl;
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