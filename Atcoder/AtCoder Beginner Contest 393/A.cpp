#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

void solve(){
    string s1,s2;cin >> s1 >> s2;
    if(s1 == "sick" and s2 == "fine") cout << 2 << endl;
    if(s1 == "sick" and s2 == "sick") cout << 1 << endl;
    if(s1 == "fine" and s2 == "fine") cout << 4 << endl;
    if(s1 == "fine" and s2 == "sick") cout << 3 << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}