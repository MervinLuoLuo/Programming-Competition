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
    int n,a;cin >> n >> a;
    string s;cin >> s;
    int cnt1 = 0;
    for(char c : s){
        if(c == '1') cnt1++;
    }
    bool flag = 0;

    int r= 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            r++;
            if(r >= a + 1){flag = 1;break;}
        }
        else r = 0;
    }
    if(flag) {cout << n << endl;return;}
    r = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') r++;
        else {
            if(r >= a){flag = 1;break;}
            r = 0;
        }
    }
    if(!flag && r >= a){
        if(r < n) flag = 1;
    }
    if(!flag){
        int i = 0;
        while(i < n){
            if(s[i] == '1'){
                int j = i;
                while(j < n && s[j] == '1') j++;
                int len = j - i;
                if(len >= a && ((i > 0 && s[i - 1] == '0') || (j < n && s[j] == '0'))){
                    flag = 1;break;
                }
                i = j;
            }
            else i ++;
        }
    }
    if(flag) cout << n << endl;
    else cout << cnt1 << endl;
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