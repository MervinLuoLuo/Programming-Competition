#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    int n,x,y;cin >> n >> x >> y;
    string s;cin >> s;
    int cnt4 = 0, cnt8 = 0;

    for(char c : s){
        cnt4 += (c == '4');
        cnt8 += (c == '8');
    }

    x = abs(x), y = abs(y);
    if(cnt4 + 2 * cnt8 < x + y) cout << "NO" << endl;
    else if(cnt4 + cnt8 < max(x ,y)) cout << "NO" << endl;
    else cout << "YES" << endl;
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