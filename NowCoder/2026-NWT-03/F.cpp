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
    int ans = n - 1;
    int add = n / 8;
    if(n % 8 == 3 || n % 8 == 4 || n % 8 == 5 || n % 8 == 6) add++;
    else if(n % 8 == 7) add += 2;
    ans += add;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}