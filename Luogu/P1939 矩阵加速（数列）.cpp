/*https://www.luogu.com.cn/problem/P1939*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int MOD = 1e9 + 7;

struct Mat{
    int n;
    VII a;
    Mat(int n_, bool ident = 0) : n(n_),a(n + 1,vector<int>(n + 1, 0)){
        if(ident){
            for(int i = 1; i <= n; i++) a[i][i] = 1;
        }
    }
};

Mat operator *(const Mat &x, const Mat& y){
    int n = x.n;
    Mat res(n);
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j] % MOD) % MOD;
            }
        }
    }
    return res;
}

Mat matpow(Mat a,int b){
    Mat res(a.n, 1);
    while(b){
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n;cin >> n;
    if(n <= 3){
        cout << 1 << endl;
        return;
    }
    Mat M(3);
    M.a[1][1] = M.a[1][3] = M.a[2][1] = M.a[3][2] = 1;

    Mat Mn = matpow(M, n - 3);
    int ans = (Mn.a[1][1] + Mn.a[1][2] + Mn.a[1][3]) % MOD;
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