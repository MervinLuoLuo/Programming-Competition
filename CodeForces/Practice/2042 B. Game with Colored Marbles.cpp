/*https://codeforces.com/problemset/problem/2042/B*/
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
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        mp[x]++;
    }

    int cnt = 0;
    int ans = 0;
    for(auto it : mp){
        if(it.second == 1) cnt++;
        else if(it.second > 1) {ans++;}
    }
    int add = (cnt / 2) * 2 + ((cnt & 1) ? 2 : 0);
    // cout << add << " ";
    ans += add;
    cout << ans << endl;

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