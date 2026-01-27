/*https://codeforces.com/contest/2189*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,h,l;cin >> n >> h >> l;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    int x = 0,y = 0,b = 0;
    for(int k : a){
        if(k <= h && k <= l) b++;
        else if(k <= h) x++;
        else if(k <= l) y++;
    }   

    int ans = 0;
    int m = min(x,y);
    ans += m;x -= m;y -= m;
    if(x > 0){
        m = min(x,b);
        ans += m;
        b -= m;
    }
    if(y > 0){
        m = min(y,b);
        ans += m;
        b -= m;
    }
    ans += b / 2;

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}