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
    int n;cin >> n;
    vector<int> a(n + 5);
    for(int i = 1; i<= n; i++) cin >> a[i];
    int num = 2 * a[1] - a[2];
    int den = n + 1;
    if(num < 0 || num % den != 0){no;return;}
    int y = num / den;
    int x = a[1] - (y * n);
    if(x < 0){no;return;}
    for(int i = 1; i <= n; i++){
        if(x * i + y * (n - i + 1) != a[i]){no;return;}
    }
    yes;
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