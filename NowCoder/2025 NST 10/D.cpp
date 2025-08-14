#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
using ull = unsigned long long;
const int INF = 1e18;
const int maxn = 1e9;
const int MOD = 998244353;

void solve(){
    ull n;cin >> n;
    cout << ((n % 6 == 4) ? 2 % MOD : 0) << endl;
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