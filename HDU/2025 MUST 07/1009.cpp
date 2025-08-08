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
const int mday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
vector<pii> c;

bool checkr(int y){
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

void ini(){
    for(int i = 1; i <= 12; i++){
        int maxd = mday[i];
        for(int d = 1; d <= maxd; d++) c.push_back({i,d});
    }
    c.push_back({2,29});
}

int wday(int y, int m, int d){
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int yy = y;
    if(m < 3) yy--;
    int w = (yy + yy / 4 - yy / 100 + yy / 400 + t[m - 1] + d) % 7;
    return w;
}

void solve(){
    int k,L,R;cin >> k >> L >> R;
    vector<int> cnt;cnt.reserve(c.size());
    for(auto &p : c){
        int m = p.first, d = p.second;
        int x = 0;
        for(int y = L; y <= R; y++){
            if(m == 2 && d == 29){
                if(!checkr(y)) continue;
            }
            else{
                int maxd = mday[m];
                if(d > maxd) continue;
            }
            int w = wday(y,m,d);
            if(w == 0 || w == 6) continue;
            x++;
        }
        cnt.push_back(x);
    }
    sort(cnt.begin(),cnt.end());
    int ans = 0;
    for(int i = 0; i < k && i < (int)cnt.size(); i++) ans += cnt[i];
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    ini();
    while(t--){
        solve();
    }
    return 0;
}