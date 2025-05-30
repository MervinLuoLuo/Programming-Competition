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
    int cnt = 0;
    if(s[0] == 'y') cnt = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == 'n' and s[i - 1] == 'n'){
            cnt++;
            i++;
        }
        if(s[i] == 'y') cnt++;
    }
    cout << cnt << endl;
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