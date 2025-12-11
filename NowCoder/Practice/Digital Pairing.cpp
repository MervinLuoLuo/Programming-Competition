/*https://ac.nowcoder.com/acm/problem/299446*/
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
    vector<int> a(2 * n + 1, 0);
    for(int i = 1; i <= 2 * n; i++) cin >> a[i];
    
    int maxx = *max_element(a.begin(),a.end());
    int hset = 0; 
    if(maxx > 0) hset = 63 - __builtin_clzll(maxx);

    int ans = 0;
    for(int bit = hset; bit >= 0; bit--){
        int mask = ans | (1LL << bit);
        int cnt = 0;
        for(auto it : a){
            if((it & mask) == mask) cnt++;
            if(cnt == n) break;
        }
        if(cnt >= n) ans = mask;
    }

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