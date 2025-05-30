/*https://codeforces.com/contest/2082/problem/B*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int x, n, m;cin >> x >> n >> m;
    int ans1 = x, ans2 = x;
    if(n > 30) {cout << 0 << " " << 0 << endl;return;}
    //n > 30 时不管怎么取 x 到最后一定是 0 了
    if(m > 30) m = 30;
    //剪枝
    
    for(int i = 0; i < n + m; i++){
        if(i < m) ans1 = (ans1 + 1) >> 1;
        else ans1 >>= 1;
    }
    //取最小值
    for(int i = 0 ; i < n + m; i++){
        if(i < n) ans2 >>= 1;
        else ans2 = (ans2 + 1) >> 1;
    }
    //取最大值

    cout << ans1 << " " << ans2 << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}