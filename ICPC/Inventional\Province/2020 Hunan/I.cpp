#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int a1,b1,Y1,a2,b2,Y2,a3,b3,Y3;

void solve(){
    cin >> a2 >> b2 >> Y2 >> a3 >> b3 >> Y3;
    
    double l = 1.0 * (a2 - b1) / (Y2 - Y1) * (Y3 - Y2) + a2;
    double r = 1.0 * (b2 - a1) / (Y2 - Y1) * (Y3 - Y2) + b2;
    l = max(1.0 * a3,l),r = min(r,1.0 * b3);
    if(l <= r) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin >> a1 >> b1 >> Y1)
    solve();
    return 0;
}