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
    string s;getline(cin,s);
    string ans; ans += s[0];
    for(int i = 0 ;i < s.size();i++){
        if(s[i] == ' ') ans += s[i + 1];
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    cin.ignore();
    while(t--){
        solve();
    }
    return 0;
}