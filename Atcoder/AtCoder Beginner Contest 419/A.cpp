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
    if(s == "red") cout << "SSS" << endl;
    else if(s == "blue") cout << "FFF" << endl;
    else if(s == "green") cout << "MMM" << endl;
    else cout << "Unknown" << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}