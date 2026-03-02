/*https://ac.nowcoder.com/acm/problem/17386*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

struct Mat{
    int n,m;
    VII a;
    Mat (int n_,int m_, bool ident = 0): n(n_),m(m_), a(n + 1,vector<int>(m + 1, 0)){}
};

Mat operator *(const Mat &x, const Mat &y){
    Mat res(x.n,y.m);

    for(int k = 1;k <= x.m; k++){
        for(int i = 1; i <= x.n; i++){
            for(int j = 1; j <= y.m; j++){
                res.a[i][j] += x.a[i][k] * y.a[k][j];
            }
        }
    }
    return res;
}

void solve(){
    int n,m,p,q;cin >> n >> m >> p >> q;
    Mat A(n,m);Mat B(p,q);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> A.a[i][j];
    }
    for(int i = 1;i <= p; i++){
        for(int j = 1; j <= q; j++) cin >> B.a[i][j];
    }

    if(m != p){
        cout << "ERROR" << endl;
        return;
    }
    
    Mat res = A * B;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= q; j++) cout << res.a[i][j] << " ";
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case "<< i << ":" << endl;
        solve();
    }
    return 0;
}