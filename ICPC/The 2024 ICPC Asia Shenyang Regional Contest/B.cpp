#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    if(gcd(n,m) != 1){no;return;}

    yes;
    for(int i = 1; i <= n; i++) cout << (i * m + 1) % (n * m) << " ";
    cout << endl;
    for(int i = 1; i <= m; i++) cout << (i * n + 1) % (n * m) << " ";
    cout << endl;
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