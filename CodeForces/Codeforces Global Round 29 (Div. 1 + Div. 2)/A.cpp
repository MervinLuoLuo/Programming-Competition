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
    int x,y;cin >> x >> y;
    if(y == 1 || (x >= y && (x - y <= 1))) cout << -1 << endl;
    else{
        if(x < y) cout << 2 << endl;
        else cout << 3 << endl;
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