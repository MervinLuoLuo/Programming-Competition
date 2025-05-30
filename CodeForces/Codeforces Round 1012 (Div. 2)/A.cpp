/*https://codeforces.com/contest/2090/problem/A*/
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
    int x,y,aa;cin >> x >> y >> aa;
    int sum = x + y;
    double a = (aa % sum) * 1.0 + 0.5;
    if(a - x <= 0) no;
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