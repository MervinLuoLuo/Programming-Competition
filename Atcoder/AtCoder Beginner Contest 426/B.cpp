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
    string s;cin >> s;
    map<char,int> freq;
    int n = s.size();
    for(int i = 0; i < n; i++){
        freq[s[i]]++;
    }
    char ans = 'a';
    for(auto it : freq){
        if(it.second == 1) ans = it.first;
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}