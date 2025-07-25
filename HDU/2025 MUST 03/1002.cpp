#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    vector<int> b(n),c(n),a(n);
    for(int &x : b) cin >> x;     
    for(int &x : c) cin >> x;
    
    vector<int> sufmin(n + 1, 0), sufmax(n + 1, 0);
    int prev = 0;
    for(int i = 0; i < n;i++){
        int x = max(b[i],prev);
        if(x > c[i]){no;return;}
        prev = x;
        sufmin[i + 1] = sufmin[i] + x;
    }

    int summin = sufmin[n];
    prev = 0;
    a[n - 1] = c[n - 1];
    
    for(int i = n - 2; i >= 0; i--){
        a[i] = min(c[i],a[i + 1]);
        if(a[i] < b[i]){no;return;}
    }

    int summax = accumulate(a.begin(),a.end(),0LL);
    if(m >= summin && m <= summax) yes;
    else no;
    

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