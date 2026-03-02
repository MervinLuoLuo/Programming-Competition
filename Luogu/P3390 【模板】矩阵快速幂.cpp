/*https://www.luogu.com.cn/problem/P3390*/
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

    Mat(int n_, bool ident = false): n(n_), a(n_ + 1, vector<long long>(n_ + 1, 0)){
        if(ident) {
            for(int i = 1; i <= n; i++) a[i][i] = 1;
        }
    }

};

Mat operator *(const Mat &x ,const Mat &y){
    Mat res(x.n);
    int n = x.n;
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
    int n = a.n;    
    Mat res(n, true);

    while(b){
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }

    return res;
}

void solve(){
    int n,k;cin >> n >> k;
    Mat M(n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> M.a[i][j];
        }
    }

    Mat res = matpow(M,k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << res.a[i][j] << " ";
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}