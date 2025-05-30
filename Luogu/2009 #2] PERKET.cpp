/*https://www.luogu.com.cn/problem/P2036*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int n, ans = maxn;
vector<pii> a;

void dfs(int x,int s, int b, int cnt){
    // x:当前选择位置 s: 酸度 b: 苦度 cnt: 已选择食材数
    if(x == n){
        if(cnt == 0) return;
        ans = min (ans, abs(s - b));
        return;
    }
    dfs(x + 1, s * a[x].first,b+a[x].second,cnt + 1);
    dfs(x + 1, s,b,cnt);
}
void solve(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin>> a[i].first >> a[i].second;
    dfs(0,1, 0,0);
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}