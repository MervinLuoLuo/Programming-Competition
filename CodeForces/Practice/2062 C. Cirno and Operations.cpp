#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 5);
    for(int i = 1; i <= n ;i++) cin >> a[i];
    int ans = accumulate(a.begin(),a.end(),0ll);
    int cnt = 1;
    while(cnt < n){
        ans = max(ans,abs(a[n]-a[cnt++]));
        for(int i = n; i >= cnt; i--) a[i] -= a[i - 1];
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}