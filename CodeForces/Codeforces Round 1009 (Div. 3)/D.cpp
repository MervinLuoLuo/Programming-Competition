/*http://codeforces.com/contest/2074/problem/D*/
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
    vector<int> x(n),r(n);
    for(int i = 0; i < n; ++i) cin >> x[i];
    for(int i = 0; i < n; ++i) cin >> r[i];
    map<int,int> mp;//存横坐标为 x 的有多少个点
    for(int i = 0; i < n; i++){
        for(int xnow = x[i] - r[i]; xnow <= x[i] + r[i]; xnow++){
            int cnt = sqrt(r[i] * r[i] - (abs(x[i] - xnow) * abs(x[i] - xnow)));
            //算含点数 但是只有一半
            mp[xnow] = max(mp[xnow],2 * cnt + 1);//另外一半 + 圆心
        }
    }
    int ans = 0;
    for(auto it : mp) ans += it.second;
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