#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 998244353;

int qpow(int a,int b){
    int res = 1;
    a %= MOD;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int MODC(int n){
    return qpow(n,MOD - 2);
}

// 直接列举 0 ~ 9 需要的灯管
int digi[10][7] = {
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};

void solve(){
    int C;cin >> C;
    int inv = MODC(100);
    vector<int> p(7);
    for(int i = 0; i < 7; i++){
        int x;cin >> x;
        p[i] = (x * inv) % MOD;
    }

    // 计算各个数字成像概率
    vector<int> P(10);
    for(int d = 0; d < 10;d++){
        int cur = 1;
        for(int i = 0; i < 7; i++){
            if(digi[d][i] == 1) cur = (cur * p[i]) % MOD;
            else cur = (cur * (1 - p[i] + MOD)) % MOD;
        }
        P[d] = cur;
    }

    VII dp(5,vector<int>(2,0));
    dp[0][0] = 1;
    int c = C;
    for(int i = 0; i < 4; i++){
        int tar = c % 10;
        c /= 10;
        for(int j = 0; j < 2; j++){
            if(dp[i][j] == 0) continue;
            for(int a = 0; a < 10; a++){
                for(int b = 0; b < 10; b++){
                    int sum = a + b + j;
                    if(sum % 10 == tar){
                        //满足条件 更新状态
                        int nj = sum / 10;
                        int way = (P[a] * P[b]) % MOD;
                        dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][j] * way) % MOD; 
                    }
                }
            }
        }
    }

    cout << dp[4][0] << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}