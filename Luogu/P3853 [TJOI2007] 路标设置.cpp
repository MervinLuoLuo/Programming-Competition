/*https://www.luogu.com.cn/problem/P3853*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int l,n,k;
vector<int> a, diff;

bool check(int x){
    int cnt = 0;
    for(int i = 1; i <= n + 1; i++){
        if(diff[i] > x){
            cnt += (diff[i] - 1) / x;
        }
    }
    return cnt <= k;
}

void solve(){
    cin >> l >> n >> k;
    a.resize(n + 5);diff.resize(n + 5);
    a[0] = 0, diff[0] = 0;
    for(int i = 1; i <= n; i++) {cin >> a[i];diff[i] = a[i] - a[i - 1];}
    a[n + 1] = l,diff[n + 1] = a[n + 1] - a[n];
    int r = l; l = 1;
    while(l < r){ 
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;        
    }
    if(!check(l)) cout << r << endl;
    else cout << l << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t--){
       solve();
    }
    return 0;
}