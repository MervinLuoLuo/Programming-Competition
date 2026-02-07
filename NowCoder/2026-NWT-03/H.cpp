#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int xa,ya,xb,yb;cin >> xa >> ya >> xb >> yb;
    double C = xa * yb - xb * ya, A = ya - yb;
    if(fabs(A) < 1e-9){
        if(fabs(fabs(C) - 4.0) < 1e-9) cout << fixed << setprecision(10) << 0.0 << endl;
        else cout << "no answer" << endl;
    }
    else{
        double ans = (4.0 - C) / A;
        cout << fixed << setprecision(10) << ans << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
// ???? 为啥啊
