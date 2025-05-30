/*https://www.luogu.com.cn/problem/P1873*/
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int n,m;
vector<int> a;
bool check(int x){
    int get  = 0;
    for(int i = 0; i< n; i++) get += max(a[i] - x, 0LL);
    if(get >= m) return 1;
    else return 0;
}

void solve(){
    cin >> n >> m;
    a.resize(n);
    for(int &x : a) cin >> x;
    int r = *max_element(a.begin(),a.end());
    int l = 0;
    while(l + 1 < r){
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << r - 1 << endl;
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