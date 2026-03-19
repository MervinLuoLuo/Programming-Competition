/*https://ac.nowcoder.com/acm/problem/14602*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

struct Mode{
    int a;
    vector<int> v;
    vector<int> w;
};

void solve(){
    int n,W;cin >> n >> W;
    vector<Mode> m(n + 1);
    for(int i = 1; i <= n; i++){
        int a;cin >> a;
        m[i].a = a;
        m[i].v.assign(a + 1, 0);m[i].w.assign(a + 1, 0);
        for(int j = 1; j <= a; j++){
            cin >> m[i].v[j];
        }
        for(int j = 1; j <= a; j++) cin >> m[i].w[j];
    }

    vector<int> dp(W + 1);
    for(int i = 1; i <= n; i++){
        for(int j = W; j >= 0; j--){
            for(int k = 1; k <= m[i].a; k++){
                if(j >= m[i].w[k]) dp[j] = max(dp[j],dp[j - m[i].w[k]] + m[i].v[k]);
            }
        }
    }

    cout << dp[W] << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}