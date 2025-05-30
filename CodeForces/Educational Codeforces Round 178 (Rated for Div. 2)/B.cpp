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
    int n;cin >> n;
    vector<int> a(n + 5);
    for(int i = 1; i <= n;i++) cin >> a[i];
    vector<int> ans(n + 5), bf(n + 5), mpf(n + 5);
    //前缀最大和
    mpf[1] = a[1];
    for(int i = 2;i <= n; i++){
        mpf[i] = max(mpf[i - 1], a[i]);
    }
    //后缀和
    bf[n + 1] = 0;
    for(int i = n;i >= 1; i--){
        bf[i] = bf[i + 1] + a[i];
    }
    for(int k = 1;k <= n; k++){
        int sum = bf[n - k + 1];
        if(n - k >= 1) ans[k] = max(sum,sum- a[n - k + 1] + mpf[n - k]);
        else ans[k] = sum;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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