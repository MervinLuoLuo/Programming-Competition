#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int a,b;cin >> a >> b;
    if(a <= b){
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    while(b != 0 && a > b){
        a -= 2,b -= 1;
        ans++;
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