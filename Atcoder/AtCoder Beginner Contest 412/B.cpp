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
    string s,t;cin >> s >> t;
    // transform(t.begin(),t.end(),t.begin(),[](unsigned char c){
    //     return tolower(c);
    // });
    map<char,int> mp;
    for(int i = 0; i < t.size(); i++){
        mp[t[i]]++;
    }
    for(int i = 1; i < s.size(); i++){
        char cur = s[i];
        if(cur >= 'A' && cur <= 'Z' && !mp[s[i - 1]]){no;return;}
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}