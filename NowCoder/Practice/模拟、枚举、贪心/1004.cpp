/*https://ac.nowcoder.com/acm/contest/20960/1004*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

void solve(){
    int n;cin >> n;
    vector<pii> pos;
    vector<pii> str;
    for(int i = 0; i < n; i++){
        int a,b,g,k;cin >> a >> b >> g >> k;
        pos.push_back({a,b});
        str.push_back({g,k});
    }
    int x,y;cin >> x >> y;
    int ans = -1;
    for(int i = n - 1; i >= 0; i--){
        int a = pos[i].first, b = pos[i].second;
        int g = str[i].first, k = str[i].second;
        if(a <= x and a + g >= x and b <= y and b + k >= y){
            ans = i + 1;
            break;
        }
    }
    cout << ans;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}