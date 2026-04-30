#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int a,b;cin >> a >> b;
    if(b < 45){
        cout << "0.0" << endl;
        return;
    }
    double S = ceil(0.6 * a + 0.4 * b);
    if(S >= 95.0) cout << "5.0" << endl;
    else if(S >= 60 && S < 95){
        double ans = 5 - 0.1 * (95 - S);
        cout << fixed << setprecision(1) <<ans << endl;
    }
    else cout << "0.0" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}