/*https://www.luogu.com.cn/problem/B3612*/
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
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    int m;cin >> m;
    while(m--){
        int l,r;cin >> l >> r;
        cout << pre[r] - pre[l - 1] << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}