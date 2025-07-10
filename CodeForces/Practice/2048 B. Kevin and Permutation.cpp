/*https://codeforces.com/problemset/problem/2048/B*/
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
    int n,k;cin >> n >> k;
    vector<int> ans(n + 5, 0);
    int cur = 1;
    for(int i = k; i <= n; i += k){
        ans[i] = cur;
        cur++; 
    }

    for(int i = 1; i <= n; i++){
        if(ans[i] == 0) {cout << cur << " ";cur++;}
        else cout << ans[i] << " ";
    }
    cout << endl;
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