#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int a,b,c,d;cin >> a >> b >> c >> d;
    c = c - a,d = d - b;
    //第一轮
    int maxx = max(a,b),minx = min(a,b);
    int cnt = maxx / 2;
    if(maxx & 1) cnt++;
    if(cnt - 1 > minx){no;return;}
    
    //第二轮
    maxx = max(c,d),minx = min(c,d);
    cnt = maxx / 2;
    if(maxx & 1) cnt++;
    if(cnt - 1 > minx){no;return;}

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