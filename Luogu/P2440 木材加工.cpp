/*https://www.luogu.com.cn/problem/P2440*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,k;
vector<int> a(n);

bool check(int x){
    int get = 0;
    for(int i =0; i < n;i++) get += a[i] / x;
    return get >= k;
}

void solve(){
    cin >> n >> k;
    a.resize(n);
    for(int &x : a) cin >> x;
    int l = 0, r = maxn + 1;
    while(l + 1 < r){
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
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