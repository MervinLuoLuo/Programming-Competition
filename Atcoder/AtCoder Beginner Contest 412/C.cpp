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
    sort(a.begin() + 1, a.begin() + n - 1);
    int last = a[0];//记一下上一张选中的牌
    int ans = 2; 
    for(int i = 1; i <= n - 1; i++){
        if(a[n - 1] <= last * 2){
            cout << ans << endl;
            return;
        }
        if(a[i] <= last * 2 && a[i + 1] > last * 2){
            ans++;last = a[i];
        }
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