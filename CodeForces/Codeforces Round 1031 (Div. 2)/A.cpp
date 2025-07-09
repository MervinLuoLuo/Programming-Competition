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
    pii a,b;cin >> a.first >> b.first >> a.second >> b.second;
    pii cur = a.second < b.second ? a : b;
    int ans = 0;
    ans += max((k - cur.first + cur.second) / cur.second,0LL);
    k -= max((k - cur.first + cur.second) / cur.second,0LL) * cur.second;
    cur = a.first < b.first ? a : b;
    ans += max((k - cur.first + cur.second) / cur.second,0LL);
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