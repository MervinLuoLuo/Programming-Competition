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
    int ans;
    int pos = -1,minx = INT_MAX;
    bool flag = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < minx){minx = a[i];pos = i;}
        if(i != 0 && a[i] == a[i - 1]) flag = 1;
    }
    ans = (n - 1) * minx;
    if(!flag){cout << ans << endl;return;}
    for(int l = 0,r = 1;r < n; l++,r++){
        if(a[l] == a[r]){
            int i = r;
            while(i < n && a[i] == a[r]) i++;
            int len = i - l;
            ans = min(ans,(n - len) * a[r]);
            l = i - 1, r = i;
        }
    }
    cout << ans << endl;
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