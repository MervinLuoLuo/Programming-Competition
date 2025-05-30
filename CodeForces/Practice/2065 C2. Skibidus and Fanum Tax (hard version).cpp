/*https://codeforces.com/problemset/problem/2065/C2*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    vector<int> a(n + 5),b(m);
    a[0] = -INF;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int &x : b) cin >> x;
    sort(b.begin(),b.end());
    for(int i = 1;i <= n; i++){
        int dif = a[i - 1] + a[i];
        auto it = lower_bound(b.begin(),b.end(),dif);
        //满足条件就保留,不满足条件就赋值INF使得最后不影响修改
        int keep = (a[i] >= a[i - 1] ? a[i] : INF);
        int rep = INF;
        if(it != b.end()){
            if(*it - a[i] >= a[i - 1]) rep = *it - a[i];
        }
        if(rep == INF && keep == INF) continue;//如果两个方案都不可行那就往下走,直接返回 no也可以
        a[i] = min(keep,rep);
    }
    if(is_sorted(a.begin() + 1,a.begin() + n + 1)) yes;
    else no;
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