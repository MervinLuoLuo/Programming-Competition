/*https://codeforces.com/problemset/problem/1990/B*/
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
    int n,x,y;cin >> n >> x >> y;
    vector<int> a(n,1);
    x--,y--;
    int tmp = -1;
    for(int i = x + 1;i < n; i++){
        a[i] = tmp;
        tmp *= -1;
    }
    tmp = -1;

    for(int i = y - 1; i >= 0; i--){
        a[i] = tmp;
        tmp *= -1;
    }

    for(auto it : a) cout << it << " ";
    cout << endl;
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