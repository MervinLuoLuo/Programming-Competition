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

void solve(){
    int x,y;cin >> x >> y;
    int n = 10;
    vector<int> a(n);
    a[0] = x, a[1] = y;
    for(int i = 2; i < n; i++){
        int sum = a[i - 1] + a[i - 2];
        string s = to_string(sum);
        reverse(s.begin(),s.end());
        // cout << s << endl;
        int x = 0;
        while(s[x] == '0') x++;
        string ans = s.substr(x,1e5 + 1);
        a[i] = stoll(ans);
    }

    cout << a[9] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}