/*https://codeforces.com/contest/2075/problem/C*/
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
    int n,m;cin >> n >> m;
    vector<int> a(m);
    for(int i = 0;i < m; i++) {cin >> a[i];if(a[i] == n) a[i]--;}//预处理,因为a[i] == n时也用不上n个,所以--方便后面运算
    sort(a.begin(),a.end());
    vector<int> suf(m + 1);
    for(int i = m - 1; i >= 0;i--){
        suf[i] = suf[i + 1] + a[i];
    }
    //后缀和(当然从大到小排序就可以用前缀和了)
    int ans = 0;
    for(int i = 0; i < m; i++){
        auto it  = lower_bound(a.begin() + i + 1, a.end(),n - a[i]);//二分找a[x],加快速度
        if(it!= a.end()){
            int x = a.end() - it;
            int now = suf[it-a.begin()] + x *(a[i] - n + 1);//计算公式
            now *= 2;//记得乘2
            ans += now;
        }
    }
    cout << ans << endl;
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