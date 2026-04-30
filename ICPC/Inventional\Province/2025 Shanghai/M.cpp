#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,x,y;cin >> n >> x >> y;
    int sum = 0;
    vector<int> a(n + 1);
    for(int i = 1; i <= n ;i ++){
        cin >> a[i];
        sum += a[i];
    }

    int ans = INF,cost = 0;
    while(1){
        if(sum <= (INF - cost - 1) / x) ans = min(ans,cost + sum * x);
        if(sum == 0) break;
        
        cost += y;
        for(int i = 1; i <= n; i++){
            if(a[i] & 1) a[i]--,cost += x;
        }
        for(int i = 1; i <= n; i++) a[i] >>= 1;
        sum = 0;
        for(int i = 1; i <= n; i++) sum += a[i];
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}