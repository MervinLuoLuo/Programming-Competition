/*https://ac.nowcoder.com/acm/contest/20960/1011*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii piar<int,int>
#define yes cout<< "Yes" << endl
#define no cout << "No" << endl
using namespace std;
const int maxn = 1e9;
const int INF = 1e18;

void solve(){
    int n, b;cin >> n >> b;
    vector<int> a(n), hash(2 * n);
    int p = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < b) a[i] = -1;
        else if(a[i] > b) a[i] = 1;
        else p = i;
    }
    int ans = 1;
    int sum = 0;
    for(int i = p + 1; i < n; i++){
        sum += a[i];
        if(sum == 0) ans++;
        hash[n + sum]++;
    }
    sum = 0;
    for(int i = p - 1; i >= 0; i--){
        sum += a[i];
        if(sum == 0) ans++;
        ans +=hash[n - sum];
    }
    cout << ans << endl;
}
signed main(){
    int t;
    t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}