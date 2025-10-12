/*https://codeforces.com/problemset/problem/2044/E*/
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
    int k,l1,r1,l2,r2;cin >> k >> l1 >> r1 >> l2 >> r2;
    int kn = 1,ans = 0;
    for(int i = 0; r2 / kn >= l1;i++){
        ans += max(0LL ,min(r2 / kn, r1) - max((l2 - 1) / kn + 1 ,l1)+ 1);
        kn *= k;
    }
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