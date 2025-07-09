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
    int w,h,a,b;cin >> w >> h >> a >> b;
    int x1,x2,y1,y2;cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2){
        if(abs(y1- y2) % b) no;
        else yes;
    }
    else if(y1 == y2){
        if(abs(x1-x2) % a) no;
        else yes;
    }
    else if((x1 - x2) % a == 0 || (y1-y2) % b == 0) yes;
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
