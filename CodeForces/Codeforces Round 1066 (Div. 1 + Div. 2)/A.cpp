#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    int n;cin >> n;
    map<int,int> freq;
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        freq[x]++;
    }

    int ans = 0;
    for(auto it : freq){
        if(it.first < it.second) ans += it.second - it.first;
        else if (it.first > it.second) ans += it.second;
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