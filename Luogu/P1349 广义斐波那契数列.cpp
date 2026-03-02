/*https://www.luogu.com.cn/problem/P1349*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int p,q,m;

struct Mat{
    int n;
    VII a;

    Mat (int n_, bool ident = 0) : n(n_), a(n + 1,vector<int>(n + 1)){
        if(ident){
            for(int i = 1; i <= n; i++) a[i][i] = 1;
        }
    }
};

Mat operator *(const Mat &x, const Mat &y){
    int n = x.n;
    Mat res(n);

    for(int k = 1;k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j  = 1; j <= n; j++){
                res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j] % m) % m; 
            }
        }
    }
    return res;
}

Mat matpow(Mat a,int b){
    Mat res(a.n,true);

    while(b){
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){
    int a1,a2,n;cin >> p >> q >> a1 >> a2 >> n >> m;
    if(n == 2) {cout << a2 << endl;return;}
    if(n == 1){cout << a1 << endl;return;}

    Mat M(2);
    M.a[1][1] = p,M.a[1][2] = q,M.a[2][1] = 1;

    Mat Mn = matpow(M,n - 2);
    int ans = (Mn.a[1][1] * a2 % m + Mn.a[1][2]* a1 % m) % m;

    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}