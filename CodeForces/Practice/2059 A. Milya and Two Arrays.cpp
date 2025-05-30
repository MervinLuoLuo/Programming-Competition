/*https://codeforces.com/problemset/problem/2059/A*/
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
    vector<int> a(n),b(n);
    set<int> as, bs;
    for(int i = 0; i < n; i++) {cin >> a[i];as.insert(a[i]);}
    for(int i = 0; i < n; i++) {cin >> b[i];bs.insert(b[i]);}
    if(as.size() + bs.size() < 4) no;
    else yes;
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