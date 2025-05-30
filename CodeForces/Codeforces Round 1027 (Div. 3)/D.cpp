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
    vector<pii> a(n);
    map<int,int>xc,yc;
    vector<int> xv,yv;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        xv.push_back(a[i].first);
        yv.push_back(a[i].second);
        xc[a[i].first]++;yc[a[i].second]++;
    }
    if(n == 1){cout << 1 << endl;return;}
    sort(xv.begin(),xv.end());
    sort(yv.begin(),yv.end());
    int x1 = xv[0],x2 = xv[1],x3 = xv[n -2],x4 = xv[n - 1];
    int y1 = yv[0],y2 = yv[1],y3 = yv[n - 2],y4 = yv[n - 1];

    int w = x4 - x1  + 1;
    int h = y4- y1 + 1;
    int ans = w * h;

    for(int i = 0; i < n; i++){
        int x = a[i].first,y = a[i].second;
        int nx1 = (x == x1 && xc[x1] == 1)? x2 : x1;
        int nx2 = (x == x4 && xc[x4] == 1)? x3 : x4;
        int ny1 = (y == y1 && yc[y1] == 1)? y2 : y1;
        int ny2 = (y == y4 && yc[y4] == 1)? y3 : y4;

        int nw = nx2 - nx1 + 1;
        int nh = ny2 - ny1 + 1;
        int area = nw * nh;
        if(area == n - 1) area += min(nw,nh);
        ans = min(ans, area); 
    }
    cout << ans << endl;
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