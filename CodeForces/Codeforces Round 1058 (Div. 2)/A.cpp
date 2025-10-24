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
    vector<int> a(n);
    bool flag = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) flag = 1;
    }
    if(flag){
        sort(a.begin(),a.end());
        int ans = *a.rbegin() + 1;
        for(int i = 1; i < n; i++){
            if(a[i] -1 > a[i - 1]){
                ans = a[i - 1] + 1;
                break;
            }
        }
        cout << ans << endl;
    }
    else{
        cout << 0 << endl;
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