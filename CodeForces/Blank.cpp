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

string calc(int x){
    string s = "";
    while(x){
        int cur = x % 2;
        x /= 2;
        char add = cur + '0';
        s = s + add;
    }
    reverse(s.begin(),s.end());
    return s;
}
void solve(){
    int n;cin >> n;
    for(int s = n; ; s = (s - 1) & n){
        if(s == 0) break;
        string Bit = calc(s); 
        cout << s << " " << Bit << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}