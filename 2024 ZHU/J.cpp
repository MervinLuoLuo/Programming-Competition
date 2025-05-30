#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

void solve(){
    string s;cin >> s;
    bool flag = 0;
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == s[i + 1] and s[i] != '?'){flag = 1;break;}
    }
    if(flag){cout << -1 << endl;return;}
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            for (char c : {'A', 'B', 'C'}) {
                if ((i > 0 && s[i - 1] == c) || (i < s.size() - 1 && s[i + 1] == c)) {
                    continue;
                }
                s[i] = c;
                break;
            }
        }
    }
    cout << s << endl;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}