/*https://codeforces.com/problemset/problem/2003/C*/
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
    map<char,int> mp;
    for(int i = 0; i < n; i++) mp[s[i]]++;
    vector<pair<int,char>> a;
    for(auto it : mp) a.push_back({it.second,it.first});
    sort(a.begin(),a.end(),[](pair<int,char> a, pair<int,char> b){
        return a.first > b.first;
    });

    int i = 0;
    string ans (n,'$');
    for(const auto &it : a){
        int x = it.first;
        char c = it.second;
        while(x--){
            if(i >= n) i = 1;
            ans[i] = c;
            i += 2;
        }
    }
    cout << ans << endl;
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