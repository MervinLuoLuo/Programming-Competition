#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    string s;cin >> s;
    int n = s.size();
    s = " " + s;

    //不可能情况
    if(s[1] != '>'|| s[n] != '>' || s[n - 1] != '>' || s[n - 2] != '>' ) {no;return;}
    if(count(s.begin(),s.end(),'-') == 0){no;return;}

    //可能情况
    cout << "Yes ";
    vector<pii> ans;

    int r = n;
    while(r >= 1 && s[r] == '>') r--;
    int rstart = r + 1;

    //Step 1: 用多次标准字串构造最右边的连续 '>' 串
    for(int i = n; i >= rstart; i--){
        int start = max(1LL, i - 4);
        ans.push_back({start, 5});
    }

    //Step 2 : 以最右侧连续 '>' 串的头三个作为终点,从左往右遍历,
    //         如果遇到 '>' 那就以这个 '>' 为起点,中间全放 '-' 构造
    //         一定能构造成功
    for(int i = 1; i <= rstart - 2; i++){
        if(s[i] == '>') {
            int len = rstart - i + 3;
            ans.push_back({i,len});
        }
    } 

    cout << ans.size() << endl;
    for(auto &[u,v] : ans) cout << u << " " << v << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}