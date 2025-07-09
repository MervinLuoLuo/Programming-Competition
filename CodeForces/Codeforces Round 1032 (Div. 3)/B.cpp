#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int cnt = 0;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    map<char,int> mp;
    mp[s[0]] ++;mp[s[n - 1]]++;
    for(int i = 1; i <n- 1; i++){
        mp[s[i]]++;
        if(mp[s[i]] > 1){yes;return;}
    }
    no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cnt++;
        solve();
    }
    return 0;
}