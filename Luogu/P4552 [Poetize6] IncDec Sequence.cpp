/*https://www.luogu.com.cn/problem/P4552*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1, 0);
    int add = 0,sub = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++){
        int d = a[i] - a[i - 1];
        if(d > 0) add += d;
        else sub -= d;
    }

    cout << min(add,sub) + abs(add - sub) << endl;
    int ans= abs(add-sub) + 1;
    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}