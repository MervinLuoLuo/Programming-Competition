/*https://www.luogu.com.cn/problem/P13363*/
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
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int xs = a[1],sum = accumulate(a.begin() + 1,a.end(),0LL);
    for(int i = 2; i <= n; i++) xs ^= a[i];
    if(xs != 0){
        cout << "NO" << endl;
        return;
    }
    int minx = *min_element(a.begin() + 1,a.end());
    cout << sum - minx << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    for(int i = 1; i <= t;i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}