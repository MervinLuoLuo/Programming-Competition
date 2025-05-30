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
    string s;cin >> s;
    s = " " + s;
    vector<int> ans(n + 5);
    int maxx = n ,minx = 1;
    for(int i = n - 1; i >= 1; i--){
        if(s[i] == '<') {ans[i + 1] = minx;minx++;}
        else {ans[i + 1] = maxx;maxx--;}
    }
    ans[1] = minx;
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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