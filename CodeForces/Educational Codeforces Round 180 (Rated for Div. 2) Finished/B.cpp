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
    vector<int> a(n);
    for(int &x : a) cin >> x;
    for(int i = 0; i < n - 1; i++){
        if(abs(a[i] - a[i + 1]) <= 1) {cout << 0 << endl;return;}
    }
    for(int i = 1; i < n - 1; i++){
        if(a[i] > a[i - 1] && a[i] > a[i + 1]){cout << 1 << endl;;return;}
        if(a[i] < a[i - 1] && a[i] < a[i + 1]){cout << 1 << endl;return;}
    }
    cout << -1 << endl;
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