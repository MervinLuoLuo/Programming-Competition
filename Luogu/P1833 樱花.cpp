/*https://www.luogu.com.cn/problem/P1833*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ll long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int aa1,bb1,aa2,bb2;
    scanf("%d:%d",&aa1,&bb1);
    scanf("%d:%d",&aa2,&bb2);
    ll W = (aa2 - aa1) * 60 + (bb2 - bb1);
    int n;scanf("%d",&n);
    vector<ll> w(n + 1),val(n + 1),k(n + 1);
    for(int i = 1; i <= n; i++){
        scanf("%lld %lld %lld",&w[i],&val[i],&k[i]);
    }

    vector<ll> dp(W + 1,0); 

    for(int i = 1; i <= n;i++){
        if(k[i] == 0){
            for(int j = w[i]; j <= W; j++) dp[j] = max(dp[j],dp[j - w[i]] + val[i]);
        }
        else{
            int cnt = 1,rem = k[i];
            while(rem > 0){
                ll kk = min(rem,cnt);
                rem -= kk;
                ll ww = w[i] * kk, vv = val[i] * kk;
                for(int j = W; j >= ww; j--){
                    dp[j] = max(dp[j],dp[j - ww] + vv);
                }
                cnt *= 2;
            }
        }
    }

    printf("%lld",dp[W]);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}