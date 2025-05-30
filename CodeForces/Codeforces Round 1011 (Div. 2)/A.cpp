/*https://codeforces.com/contest/2085/problem/A*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    string s, rs;
    cin >> s;
    rs = s;
    set<char> alpha;
    for(int i = 0; i < n; i++) alpha.insert(s[i]);
    if(alpha.size() == 1){no;return;}
    if(k){yes;return;}
    reverse(rs.begin(),rs.end());
    if(s < rs) yes;
    else no;
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