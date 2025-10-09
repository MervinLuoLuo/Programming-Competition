/*https://codeforces.com/problemset/problem/2021/A*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(),a.end());
    
    while(a.size() > 1){
        int x = a[0],y = a[1];
        a.erase(a.begin());a.erase(a.begin());
        int res = (x + y) >> 1;
        a.insert(a.begin(),res);
    }
    cout << a[0] << endl;
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