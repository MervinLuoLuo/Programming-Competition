/*https://codeforces.com/problemset/problem/2060/D*/
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
    vector<int> a(n);
    for(int &x : a) cin >> x;
    if(is_sorted(a.begin(),a.end())){yes;return;}
    int pos = 0;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i - 1]) pos = i;
    }
    for(int i = 0; i < pos; i++){
        int minx = min(a[i],a[i + 1]);
        a[i] -= minx;
        a[i + 1] -= minx;
    }
    if(is_sorted(a.begin(),a.end())) yes;
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