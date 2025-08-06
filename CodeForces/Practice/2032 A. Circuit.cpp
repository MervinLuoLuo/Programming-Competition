/*https://codeforces.com/problemset/problem/2032/A*/
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
    n *= 2;
    int cnt0 = 0,cnt1 = 0;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        if(x == 1) cnt1++;
        else cnt0++;
    }
    if(cnt1 & 1) cout << 1 << " ";
    else cout << 0 << " ";
    int ans = min(cnt1,cnt0);
    cout << ans << endl;

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