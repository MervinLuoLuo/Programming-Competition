/*https://codeforces.com/problemset/problem/2053/C*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    int mul = n + 1,ans = 0, cur = 1;
    while(n >= k){
        if(n & 1) ans += cur;
        cur <<= 1;
        n >>= 1;
    }
    cout << mul * ans / 2 << endl;
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