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
    int n,q;cin >>n >> q;
    vector<int> diff(n + 1);
    int sum = 0;
    diff[0] = 0;
    for(int i = 0; i < q; i++){
        int a,b;cin >> a >> b;
        sum += a / n;
        int res = a % n;
        if(res == 0) continue;
        int l = b, r = (b + res - 1) % n;
        if(l <= r){
            diff[l] += 1;
            diff[r + 1] -= 1;
        }
        else{
            diff[l] += 1;
            diff[r + 1] -= 1;
            diff[0] += 1;
            diff[n] -= 1;
        }
    }
    vector<int> ans(n + 1);
    int cur = 0;
    for(int i = 0; i < n; i++){
        cur += diff[i];
        ans[i] = cur + sum;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}