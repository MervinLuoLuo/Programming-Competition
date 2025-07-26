#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n = 13;
int sum;
vector<int> a;
bool check(int mid){
    int l = 0, r = 0;
    for(int i = 1; i <= n; i++){
        int R = a[i] / 3;
        int L = (a[i] - sum + 3 * mid);
        if(L < 0) L = 0;
        else L = (L + 1) >> 1;
        if(L > R) return 0;
        l += L;r += R; 
    }
    if(l <= mid && r >= mid) return 1;
    return 0;
}

void solve(){
    a.assign(n + 1,0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sum = accumulate(a.begin() + 1,a.end(),0LL);
    
    int l = 0, r = sum / 4;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
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