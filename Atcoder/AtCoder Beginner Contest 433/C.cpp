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
    string s;cin >> s;
    int n = s.size();
    s = " " + s;

    int ans = 0;
    int l = 1, r = 1;
    while(r <= n){
        while(s[l] == s[r]) r++;
        int pos = r;
        int lenl = r - l;
        char L = s[l], R = s[r];
        while(s[r] == R) r++;
        if(R != L + 1){
            l = pos;
            continue;    
        }
        ans += min(lenl,r - pos);
        l = pos;
        if(l == r) l++ ,r ++;
    }

    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}