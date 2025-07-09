#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int trans(char c){
    if(c == 'M') return 1;
    else if(c == 'K') return 2;
    else if (c == 'G') return 3;
    else if(c == 'F') return 4;
    else if(c == 'A') return 5;
    else if(c == 'B') return 6;
    else if(c == 'O') return 7;
}
void solve(){
    string s1,s2;cin >> s1 >> s2;
    if(s1[0] == s2[0]){
        if(s1[1] == s2[1]){cout << "same" << endl;return;}
        cout << (s1[1] < s2[1] ? "hotter" : "cooler") << endl;
        return;
    }
    cout << (trans(s1[0]) > trans(s2[0]) ? "hotter" : "cooler") << endl;
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