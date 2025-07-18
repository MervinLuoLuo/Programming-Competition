/*https://codeforces.com/problemset/problem/2020/B*/
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
    int k;cin >> k;
    int l = 1, r = 2e18;
    while(r - 1 > l){
        int mid = l + ((r - l) >> 1);
        int n = mid - signed(sqrtl(mid));
        if(n >= k) r = mid;
        else l = mid;
    }
    cout << r << endl;
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