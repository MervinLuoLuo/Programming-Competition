#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    if(n < 11){cout << 0 << endl;return;}
    string target = "uwawauwa";
    s = ' ' + s + ' ';
    int ans = 0;
    int cntu = 0;
    for(int i = 1; i <= n; i++){
        string t = s.substr(i + 1, 8);
        if(t == target) ans += cntu;
        cntu += (s[i] == 'u');
    }
    cout << ans << endl;
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