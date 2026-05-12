#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    // i - 1 位置所有可能状态
    int pre = a[0];
    set<int> s1 = {a[0] + k},s2;

    for(int i = 1; i < n; i++){
        // i 位置所有可能状态
        set<int> nx1,nx2;
        // i = l 的状态转移
        nx1.insert(gcd(pre,a[i] + k));
        // i 在 [l,r] 内的状态转移
        for(int x : s1) nx1.insert(gcd(x,a[i] + k));
        // i = r 的状态转移
        for(int x : s1) nx2.insert(gcd(x,a[i]));
        // i > r 的状态转移
        for(int x : s2) nx2.insert(gcd(x,a[i]));

        // 把 i 所有可能状态更新
        s1 = move(nx1);
        s2 = move(nx2);
        pre = gcd(pre,a[i]);
    }

    // 取三个状态的可能最大值
    int ans = pre;
    if(!s1.empty()) ans = max(ans,*s1.rbegin());
    if(!s2.empty()) ans = max(ans,*s2.rbegin());

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