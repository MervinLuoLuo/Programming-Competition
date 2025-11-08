#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,x;cin >> n >> x;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int l = 1, r = n;

    int sum = 0,cur = 0;
    int res = 0;
    vector<int> ans;
    while(l <= r){
        int nw = (sum + a[r]) / x;
        if(nw > cur){
            ans.push_back(a[r]);
            sum += a[r];
            cur = sum / x;
            res += a[r];
            r--;
        }
        else {
            ans.push_back(a[l]);
            sum += a[l];
            cur = sum / x;
            l++;
        }
    }

    cout << res << endl;
    for(auto it : ans) cout << it << " ";
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}