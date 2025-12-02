/*https://codeforces.com/contest/2170*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    int n;cin >> n;
    if(n == 1) cout << 1 << endl;
    else if(n == 2) cout << 9 << endl;
    else if(n == 3) cout << 29 << endl;
    else if(n == 4) cout << 56 << endl;
    else {
        int maxx = n * n;
        int mid = maxx - n - 1;
        int ans = 5 * mid;
        cout << ans << endl;
    }
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