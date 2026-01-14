/*https://codeforces.com/contest/2180*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int l,a,b;cin >> l >> a >> b;
    int ans = a;
    int cur = (a + b) % l;
    while(cur != a){
        ans = max(ans, cur);
        cur = (cur + b) % l;
    }

    cout << ans << endl; 
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}