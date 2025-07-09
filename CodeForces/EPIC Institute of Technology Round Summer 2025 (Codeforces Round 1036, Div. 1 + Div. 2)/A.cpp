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
    if(n == 1 || is_sorted(a.begin(),a.end())){no;return;}
    yes;
    cout << 2 << endl;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i - 1]) {cout << a[i - 1] << " " << a[i] << endl;return;}
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