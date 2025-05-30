#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int log2(int x) {
    return x > 0 ? 32 - __builtin_clz(x) : 0;
}
void solve(){
    int n,m,x,y;cin >> n >> m >> x >> y;
    int h = min(x,n - x + 1), w = min(y,m - y + 1);//处理第一次

    int op1 = log2(h - 1) + log2(m - 1);//先横切后竖切
    int op2 = log2(n - 1) + log2(w - 1);//先竖切再横切
    int ans = min(op1 ,op2) + 1;
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while(t--){
       solve();
    }
    return 0;
}