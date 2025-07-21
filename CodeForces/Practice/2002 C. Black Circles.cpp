/*https://codeforces.com/problemset/problem/2002/C*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int dist(int a, int b,int c,int d){
    return (c - a) * (c - a) + (d - b) * (d - b);
}

void solve(){
    int n;cin >> n;
    vector<pii> pos(n);
    for(pii &x : pos) cin >> x.first >> x.second;
    int a,b,c,d;cin >> a >> b >> c >>d;

    for(int i = 0; i < n; i++){
        int x = pos[i].first,y = pos[i].second;
        if(dist(c,d,x,y) <= dist(c,d,a,b)){no;return;}
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