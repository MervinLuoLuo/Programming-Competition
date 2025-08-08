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
    bool flag = 0;
    if(s[0] == '-'){
        s = s.substr(1);
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] > '1'){
                s.insert(i,"1");
                flag = 1;
                break;
            }
        }
        if(!flag) s += "1";
        cout << "-" << s << endl;
    }
    else{
        int n = s.size();
        // bool flag = 0;
        for(int i = 0; i < n; i++){
            if(s[i] < '1'){
                s.insert(i,"1");
                flag = 1;
                break;
            }
        }
        if(!flag) s += '1';
        cout << s << endl;
    }
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