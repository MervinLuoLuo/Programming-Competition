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
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1,a.end(),greater<int>());

    vector<int> ans;
    ans.push_back(0);ans.push_back(0);
    int res = a[2],maxx = a[1];
    for(int i = 3; i <= n; i++){
        res += a[i];
        if(res > maxx) ans.push_back(res + maxx);
        else ans.push_back(0);
    }

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