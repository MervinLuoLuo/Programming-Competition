#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

vector<pair<char, int>> compress(const string &str) {
    vector<pair<char, int>> seg;
    int n = str.size();
    int i = 0;
    while(i < n) {
        char c = str[i];
        int cnt = 0;
        while(i < n and str[i] == c) {
            cnt++;
            i++;
        }
        seg.push_back({c, cnt});
    }
    return seg;
}
void solve(){
    string p, s;cin >> p >> s;
    vector<pair<char, int>> cp = compress(p);
    vector<pair<char, int>> cs = compress(s);
    if(cp.size() != cs.size()){no;return;}
    bool flag = 1;
    for (int i = 0; i < cp.size(); i++){
        if(cp[i].first != cs[i].first){
            flag = 0;
            break;
        }
        if(cs[i].second < cp[i].second or cs[i].second > 2 * cp[i].second) {
            flag = 0;
            break;
        }
    }
    if(flag) yes;
    else no;
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