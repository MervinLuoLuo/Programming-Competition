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
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int ans = 0;
    sort(a.begin(),a.end());
    for(int x : a){
        if(ans >= x) ans++;
        else ans--;
    }
    cout << ans << ' ';
    sort(a.begin(),a.end(),greater<int>());
    ans = 0;
    for(int x : a){
        if(ans >= x) ans++;
        else ans--;
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}