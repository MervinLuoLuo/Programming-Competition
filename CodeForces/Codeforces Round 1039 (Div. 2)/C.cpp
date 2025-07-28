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
    int n;cin >> n;
    vector<int> b(n),pre(n);
    for(int &x : b) cin >> x;
    pre[0] = b[0];
    for(int i = 1; i < n; i++){
        pre[i] = min(pre[i - 1],b[i]);
    }
    for(int i = 1; i < n; i++){
        if(b[i]>= 2 * pre[i]) {no;return;}
    }
    yes;
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