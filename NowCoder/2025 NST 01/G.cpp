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
    int n,q;cin >> n >> q;
    string s;cin >> s;
    while(q--){
        string t;cin >> t;
        int a;cin >> a;
        int ans = 0;
        for(int x = 0; x < t.size();x++){
            if(s[a + x - 1] == t[x]){
                int l = x, r = x;
                while(r < t.size() && s[a + r - 1] == t[r]) r++;
                int leng = r - l;
                ans += (1 + leng) * leng / 2;
                x = r - 1;
            }
        }
        cout << ans << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}