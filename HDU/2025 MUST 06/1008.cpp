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
const int MR = 13;
const int MMASK = 1 << MR;

vector<int> l2(MMASK);
void init(){
    for(int i = 0; i < MR; i++) l2[1 << i] = i;
}

void solve(){
    int n,m,k;cin >> n >> m >> k;
    k = min(k,m);
    vector<int> val(1 << m,0), cval(1 << m),a(m);
    for(int row = 0; row < n; row++){
        for(int i = 0; i < m; i++) cin >> a[i];

        //清空当前行子集和
        fill(cval.begin(), cval.begin() + (1 << m), 0);
        for(int s = 1;s < (1 << m); s++){
            cval[s] = cval[s & (s - 1)] + a[l2[s ^ (s & (s - 1))]];
            val[s] = max(val[s],cval[s]);
        }
    }

    //初始化dp
    vii dp(k + 1,vector<int>(1 << m, 0));

    for(int j = 0; j < k; j++){
        for(int s = 0; s < (1 << m); s++){
            for(int t = ((1 << m) - 1) ^ s;t > 0; t = (t - 1) & (((1 << m) - 1) ^ s)){
                dp[j + 1][s | t] = max(dp[j + 1][s | t],dp[j][s] + val[t]);
            }
        }
    }
    cout << dp[k][(1 << m) - 1] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    init();
    while(t--){
        solve();
    }
    return 0;
}