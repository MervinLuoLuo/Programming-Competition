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
    int ans = 0;
    ans += n;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            n /= i;
            ans += n;
        }
    }
    if(n > 1) ans++;
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}