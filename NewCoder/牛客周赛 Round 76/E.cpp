#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    long double n, k;cin >> n >> k;
    int res = 0;
    res = pow(n, (1/k));
    if(abs(n-pow(res,k))<abs(n-pow(res+1,k))){
        cout << res << endl;
    }
    else cout << res + 1 << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}