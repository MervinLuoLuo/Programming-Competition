/*https://www.luogu.com.cn/problem/P3550*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int m,d,n;cin >> m >> d >> n;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1,a.end());
    int l = 1,r = n;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] >= m - d) r = mid - 1;
        else l = mid + 1;
    }
    if(a[l] >= d * 2 + m){
        cout << 1 << endl;
        return;
    }
    if(l == n + 1){cout << 0 << endl;return;}
    int ans = 0,pos = 0;
    for(int i = n; i >= 1 && pos < d; i--){
        if(i == l) continue;
        if(a[i] - (d - pos) > 0) {
            ans++;
            pos += a[i] - (d - pos);
        }
    }
    if(pos < d && 2 * (d - pos) + m - d > a[l]){cout << 0 << endl;return;}
    if(pos >= m){cout << ans << endl;return;}
    ans ++;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}