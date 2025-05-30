#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
#define int long long
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
//typedef long long ll;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(c == '-') cnt1++;
        else cnt2++;
    }
    if(cnt1 < 2 or cnt2 < 1){cout << 0 << endl;return;}
    int ans = 0;
    int l = cnt1 / 2 , r = cnt1 - l;
    ans = l * r * cnt2;
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