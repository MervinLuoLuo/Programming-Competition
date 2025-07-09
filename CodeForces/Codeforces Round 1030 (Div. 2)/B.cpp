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
    int n;cin >> n;
    cout << 2 *n - 3 << endl;
    for(int i = 1; i<= n; i++){
        if(i != 1) cout << i << " " << 1 << " " << i << endl;
        if(i <= n - 2) cout << i << " " << i + 1 << " " << n << endl;
    }
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