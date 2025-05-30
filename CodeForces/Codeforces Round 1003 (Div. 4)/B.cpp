/*https://codeforces.com/contest/2065/problem/B*/
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
    string s; cin >> s;
    bool flag = 0;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i - 1]){
            flag = 1;
            break;
        }
    }
    if(flag == 0) cout << s.size() << endl;
    else cout << 1 << endl;
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