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

int calc(int x){
    int res = x - x / 2 - x / 3 - x / 5 - x / 7 
            + x / 6 + x / 10 + x / 14 + x / 15 + x / 21 + x / 35 
            - x / 30 - x / 42 - x / 70 - x / 105 
            + x / 210;
    return res;
}
void solve(){
    int l,r;cin >> l >> r;
    cout << calc(r) - calc(l - 1) << endl;;
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