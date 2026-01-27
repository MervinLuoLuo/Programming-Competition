/*https://codeforces.com/contest/2193*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,s,x;cin >> n >> s >> x;
    int sum = 0;
    for(int i = 0; i < n ;i ++) {
        int a;cin >> a;
        sum += a;
    }

    int need = s - sum;
    if(need < 0 || need % x) cout << "NO" << endl;
    else cout << "YES" << endl;

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}