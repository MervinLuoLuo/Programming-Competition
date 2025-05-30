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
    sort(a.begin(),a.end());
    int ans1 = 0, ans2 = 0;
    int x = a[0];
    if((a[0] + a[n - 1]) % 2 == 0){cout << 0 << endl;return;}
    for(int i = n - 1;i >= 1; i--){
        if((a[i] + x) % 2 == 0) break;
        ans1++;
    }
    int y = a[n - 1];
    for(int i = 0; i < n - 1; i++){
        if(((a[i] + y) % 2 == 0)) break;
        ans2++;
    }
    cout << min(ans1,ans2) << endl;
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