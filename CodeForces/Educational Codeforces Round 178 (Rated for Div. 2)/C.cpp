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
    if(s[0]==s[n-1]){
        if(s[0]=='A')cout <<"Alice"<<endl;
        else cout <<"Bob"<<endl;
        return;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'B') cnt++;
    }
    if(cnt == 1 and s[n - 1] == 'B') cout << "Alice" << endl;
    else if(s[n - 1]  == 'A' and s[n - 2] == 'A')cout << "Alice" << endl;
    else cout << "Bob" << endl;
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