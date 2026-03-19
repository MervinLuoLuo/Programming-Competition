/*https://codeforces.com/contest/2208*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    map<int,int> mp;
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;cin >> x;
            mp[x]++;
            res = max(res,mp[x]);
        }
    }

    if(res <= n * (n - 1)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}