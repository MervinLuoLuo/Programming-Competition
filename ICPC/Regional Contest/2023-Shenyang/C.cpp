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
    int x,y;cin >> x >> y;
    int ans = 4 - x;
    if(y == 2) ans = 2 * (3 - x);
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}