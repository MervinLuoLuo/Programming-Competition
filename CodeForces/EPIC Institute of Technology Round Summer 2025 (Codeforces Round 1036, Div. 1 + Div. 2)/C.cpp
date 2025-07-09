#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int lcm(int a,int b){
    return a / gcd(a, b) * b;
}

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int &x :a) cin >> x;
    int gcdn = 0, lcmn = 1;
    for(int i = n - 1; i >= 0; i--){
        gcdn = __gcd(gcdn,a[i]);
        lcmn = lcm(lcmn,a[i] / gcdn);
    }
    cout << lcmn << endl;
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