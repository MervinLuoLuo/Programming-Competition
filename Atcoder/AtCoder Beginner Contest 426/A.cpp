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

int trans(string s){
    if(s == "Ocelot") return 1;
    else if(s == "Serval") return 2;
    else return 3;
}

void solve(){
    string x,y;cin >> x >> y;
    int a = trans(x),b = trans(y);
    if(a < b) cout << "No" << endl;
    else cout << "Yes";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}