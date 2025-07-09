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
    int n,s;cin >> n >> s;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(),a.end());
    if(s < a[0] || s > *a.rbegin()){
        cout << (a[n - 1] - s > 0 ? a[n - 1] - s : s - a[0]) << endl;
        return;
    }
    int cnt = 0;
    if(s - *a.begin() <  *a.rbegin() - s){
        cnt = (s - *a.begin()) * 2 + *a.rbegin() - s;
    }
    else cnt = (*a.rbegin() - s) * 2 + s - *a.begin();
    cout << cnt << endl;
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