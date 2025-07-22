/*https://codeforces.com/problemset/problem/2040/A*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    vector<vector<int>> a(k);
    for(int i = 0; i < n ; i++){
        int x;cin >> x;
        a[x % k].push_back(i + 1);
    }
    
    int ans = -1;
    for(int i = 0; i < k;i++){
        if(a[i].size() == 1){ans = a[i][0];break;}
    }
    if(ans  == -1) no;
    else {yes;cout << ans << endl;}
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