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
    vector<int> a(n),b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    if(a[n - 1] != b[n - 1]) {no;return;}
    for(int i = n - 2; i >= 0; i--){
        if((a[i] != b[i]) && ((a[i] ^ a[i + 1]) != b[i]) && ((a[i] ^ b[i + 1]) != b[i])) {no;return;}
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