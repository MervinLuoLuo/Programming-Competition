/*https://codeforces.com/problemset/problem/2127/C*/
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
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<pii> vec;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int b;cin >> b;
        if(b < a[i]) swap(b,a[i]);
        ans += b - a[i];
        vec.push_back({a[i],b});
    }

    sort(vec.begin(),vec.end());

    for(int i = 1; i < n; i++){
        if(vec[i].first <= vec[i - 1].second){
            cout << ans << endl;
            return;
        }
    }
    int minx = maxn;
    for(int i = 1; i < n; i++)
        minx = min(minx,vec[i].first - vec[i - 1].second);
    
    cout << ans + 2 * minx << endl;

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