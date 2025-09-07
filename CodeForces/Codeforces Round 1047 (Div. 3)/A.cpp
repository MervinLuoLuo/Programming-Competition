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
    int k,x;cin >> k >> x;
    for(int i = 0; i < k; i++){
        if((x - 1) % 3 == 0 && (((x - 1) / 3) & 1)) x = (x - 1) / 3;
        else x *= 2;
        // cout << x << " ";
    }
    cout << x << endl;
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